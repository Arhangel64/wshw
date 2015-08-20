#include "client.h"

Client::Client(quint64 id_p, QWebSocket* socket_p, QObject *parent):
    QObject(parent),
    socket(socket_p),
    id(id_p),
    name()
{
    connectSocket();
}

Client::Client(const Client & cl):
    QObject(cl.parent()),
    socket(cl.socket),
    id(cl.id)
{
    connectSocket();
}

Client::~Client()
{
    socket->deleteLater();
}

Client& Client::operator=(const Client& cl)
{
    socket->deleteLater();
    socket = cl.socket;
    id = cl.id;
    connectSocket();
    return *this;
}

quint64 Client::getId() const
{
    return id;
}

void Client::connectSocket()
{
    connect(socket, SIGNAL(disconnected()), SIGNAL(disconnected()));
    connect(socket, SIGNAL(binaryMessageReceived(const QByteArray&)), SIGNAL(binaryMessageReceived(const QByteArray&)));
}

void Client::sendBinaryMessage(const QByteArray & ba)
{
    socket->sendBinaryMessage(ba);
}

QString Client::getName() const
{
    return name;
}

void Client::setName(const QString & name_p)
{
    name = name_p;
}
