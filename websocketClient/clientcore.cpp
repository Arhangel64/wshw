#include <QUrl>
#include <QPair>
#include "clientcore.h"

ClientCore::ClientCore(QObject *parent):
    QObject(parent),
    socket(new QWebSocket()),
    clientId(0),
    serverPort(0),
    passHash(0),
    connected(false),
    reconnection(false)
{
    initSocket();
}

void ClientCore::start()
{
    emit state(ClientCore::Connecting);
    QString websocketAddress = "ws://" + serverAddress +":"+ QString::number(serverPort) + "/";
    emit info("Connecting to " + websocketAddress);
    socket->open(QUrl(websocketAddress));
}

void ClientCore::stop(bool soft)
{
    emit state(ClientCore::Disconnecting);
    emit info("Disconnecting");
    connected = false;
    clientId = 0;
    nics.clear();
    if (!soft)
        socket->close();
}

bool ClientCore::isConnected() const
{
    return connected;
}

QString ClientCore::getServerAddress() const
{
    return serverAddress;
}

quint16 ClientCore::getServerPort() const
{
    return serverPort;
}

QString ClientCore::getNick() const
{
    return nick;
}

quint64 ClientCore::getPass() const
{
    return passHash;
}

void ClientCore::setServerAddress(const QString & address) 
{
    serverAddress = address;
}

void ClientCore::setNick(const QString & nick_p, quint64 passHash_p)
{
    nick = nick_p;
    passHash = passHash_p;
    if (connected)
    {
        requestNick();
    }
}

void ClientCore::setServerPort(quint16 port)
{
    serverPort = port;
}

void ClientCore::initSocket()
{
    socket->setParent(this);
    connect(socket, SIGNAL(connected()), SLOT(socketOpened()));
    connect(socket, SIGNAL(disconnected()), SLOT(socketDisconnected()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), SLOT(socketError()));
    connect(socket, SIGNAL(binaryMessageReceived(const QByteArray&)), SLOT(socketBinaryMessageReceived(const QByteArray&)));
}

void ClientCore::socketOpened()
{
    emit state(ClientCore::Handshaking);
    emit info("Connection established, waiting for setiing connection ID");
}

void ClientCore::socketConnected()
{
    emit state(ClientCore::Connected);
    emit info("Successfully connected");
    connected = true;
}

void ClientCore::socketDisconnected()
{
    if (connected)
    {
        stop(true);
    }
    emit state(ClientCore::Disconnected);
    emit info("Successfully disconnected");
    if (reconnection)
    {
        emit info("Reconnection");
        reconnection = false;
        start();
    }
}

void ClientCore::socketError()
{
    //printError("socket " + socket->errorString());
}

void ClientCore::requestNick()
{
    emit info("Requesting for avilability of nick "+nick);
    WNickRequest* ev = new WNickRequest(nick, passHash, clientId);
    socket->sendBinaryMessage(WEvent::serializeToQByteArray(ev));
    delete ev;
}

void ClientCore::socketBinaryMessageReceived(const QByteArray& message)
{
    WEvent * ev = WEvent::createFromQByteArray(message);
    switch (ev->getEventType())
    {
    case WEvent::tWEvent:
        break;
    case WEvent::tWSetId:
        receivedId(static_cast<WSetId*>(ev));
        break;
    case WEvent::tWMessage:
        receivedMessage(static_cast<WMessage*>(ev));
        break;
    case WEvent::tWNickResponse:
        receivedNick(static_cast<WNickResponse*>(ev));
        break;
    case WEvent::tWClientList:
        receivedClientList(static_cast<WClientList*>(ev));
        break;
    }
    delete ev;
}

void ClientCore::receivedMessage(WMessage * msg)
{
    emit message(nics.getById(msg->getSenderId()), msg->getMessage());
}

void ClientCore::receivedNick(WNickResponse * nick)
{
    if (nick->isAccepted())
    {
        emit info("Nick request accepted");
        emit nickChanged(nick->getFallback());
        if (!connected)
        {
            socketConnected();
        }
    }
    else
    {
        emit info("Nick request dinied");
        emit nickDenied();
        setNick(nick->getFallback(), qHash(""));
        if (!connected)
        {
            requestNick();
        }
    }
}

void ClientCore::receivedId(WSetId * id)
{
    clientId = id->getSenderId();
    emit info("Received connection id " + QString::number(clientId));
    requestNick();
}

void ClientCore::receivedClientList(WClientList * list)
{
    int ms = list->getModifiedSize();
    while (ms != 0)
    {
        QPair<quint64, QString> pair = list->popModified();
        nics.setNick(pair.first, pair.second);
        --ms;
    }
    int rs = list->getRemovedSize();
    while (rs != 0)
    {
        nics.removeNick(list->popRemoved());
        --rs;
    }
}

void ClientCore::reconnect()
{
    if (connected)
    {
        emit info("Reconnecting");
        reconnection = true;
        stop();
    }
}

void ClientCore::sendMessage(const QString& message)
{
    if (clientId)
    {
        WMessage* msg = new WMessage(message, clientId);
        socket->sendBinaryMessage(WEvent::serializeToQByteArray(msg));
    }
}

ClientListModel* ClientCore::getClienListModel()
{
    return &nics;
}
