#include "servercore.h"
#include "wclientlist.h"
#include <QDebug>

ServerCore::ServerCore(QObject *parent) :
    QObject(parent),
    clients(new NickStorageModel(this)),
    server(new QWebSocketServer("echo",QWebSocketServer::NonSecureMode, this)),
    sockets(),
    lastClientId(0),
    running(false)
{
    connect(server, SIGNAL(closed()), SIGNAL(stopped()));
    connect(server, SIGNAL(newConnection()), SLOT(onNewConnection()));
}

ServerCore::~ServerCore()
{
    stop();
}

void ServerCore::onNewConnection()
{
    while (sockets.contains(++lastClientId));

    Client * client = new Client(lastClientId, server->nextPendingConnection(), this);

    connect(client, SIGNAL(binaryMessageReceived(const QByteArray&)), SLOT(onBinaryMessage(const QByteArray&)));
    connect(client, SIGNAL(disconnected()), SLOT(onSocketDisconnected()));

    emit message("Connected socket with id " + QString::number(lastClientId));
    sockets[lastClientId] = client;

    WSetId* ev = new WSetId(client->getId());
    client->sendBinaryMessage(WEvent::serializeToQByteArray(ev));
    delete ev;
}

void ServerCore::start(quint16 port)
{
    if (!running && server->listen(QHostAddress::Any, port))
    {
        running = true;
        emit started(port);
    }

}

void ServerCore::stop()
{
    if (running) {
        qDeleteAll(sockets.begin(), sockets.end());
        sockets.clear();
        clients->disconnectAll();
        lastClientId = 0;
        running = false;
        server->close();
    }
}

bool ServerCore::isRunning() const
{
    return running;
}

void ServerCore::onSocketDisconnected()
{
    Client * socket = qobject_cast<Client *>(sender());
    if (socket)
    {
        emit message("Disconnected socket " + QString::number(socket->getId()));
        clients->setDisconnected(socket->getName());
        sockets.remove(socket->getId());
        castSocketDisconnected(socket->getId());
        delete socket;
    }
}

void ServerCore::onBinaryMessage(const QByteArray & message)
{
    WEvent * ev = WEvent::createFromQByteArray(message);
    switch (ev->getEventType())
    {
    case WEvent::tWEvent:
        break;
    case WEvent::tWMessage:
        castMessage(static_cast<WMessage*>(ev));
        break;
    case WEvent::tWNickRequest:
        changeNick(static_cast<WNickRequest*>(ev));
    default:
        break;
    }
    delete ev;
}

void ServerCore::castMessage(WMessage * msg)
{
    QHash<quint64, Client*>::const_iterator i = sockets.constBegin();
    while(i != sockets.constEnd())
    {
        Client* socket = *i;
        socket->sendBinaryMessage(WEvent::serializeToQByteArray(msg));
        ++i;
    }
}

void ServerCore::changeNick(WNickRequest* nick)
{
    quint64 id = nick->getSenderId();
    Client * client = sockets.value(id);
    WNickResponse* ret = new WNickResponse(true, id, nick->getNick());

    if (clients->isAvailable(ret->getFallback(), nick->getPassword()))
    {
        QString exName = client->getName();
        if (!exName.isNull())
        {
            clients->setDisconnected(exName);
        }
        else
        {
            sendClientsList(client);
        }
        client->setName(ret->getFallback());
        castClientNickUpdated(id, ret->getFallback());
        clients->add(ret->getFallback(), nick->getPassword());
        clients->setConnected(ret->getFallback(), id);
    }
    else
    {
        ret->setAccepted(false);
        ret->setFallback(clients->getAvailableNick(id));
    }
    client->sendBinaryMessage(WEvent::serializeToQByteArray(ret));
    delete ret;
}

void ServerCore::sendClientsList(Client * client)
{
    WClientList *ev = new WClientList();
    QHash<quint64, Client*>::const_iterator i;
    for (i = sockets.constBegin(); i != sockets.constEnd(); ++i)
    {
        QString nick = i.value()->getName();
        if (!nick.isNull())
        {
            ev->pushModified(i.key(), nick);
        }
    }
    client->sendBinaryMessage(WEvent::serializeToQByteArray(ev));
    delete ev;
}

void ServerCore::castClientNickUpdated(quint64 id, const QString& nick)
{
    QHash<quint64, Client*>::const_iterator i = sockets.constBegin();
    WClientList *ev = new WClientList();
    ev->pushModified(id, nick);
    while(i != sockets.constEnd())
    {
        Client* socket = *i;
        socket->sendBinaryMessage(WEvent::serializeToQByteArray(ev));
        ++i;
    }
    delete ev;
}

void ServerCore::castSocketDisconnected(quint64 id)
{
    QHash<quint64, Client*>::const_iterator i = sockets.constBegin();
    WClientList *ev = new WClientList();
    ev->pushRemoved(id);
    while(i != sockets.constEnd())
    {
        Client* socket = *i;
        socket->sendBinaryMessage(WEvent::serializeToQByteArray(ev));
        ++i;
    }
    delete ev;
}
