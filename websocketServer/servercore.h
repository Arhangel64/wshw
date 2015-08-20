#ifndef SERVERCORE_H
#define SERVERCORE_H

#include <QObject>
#include <QWebSocketServer>
#include <QHash>

#include "nickstoragemodel.h"

#include "client.h"
#include "wevent.h"
#include "wmessage.h"
#include "wsetid.h"
#include "wnickrequest.h"
#include "wnickresponse.h"

class ServerCore : public QObject
{
    Q_OBJECT
public:
    explicit ServerCore(QObject *parent = 0);
    ~ServerCore();

    bool isRunning() const;
    NickStorageModel* clients;

private:
    QWebSocketServer * server;
    QHash<quint64, Client *> sockets;
    quint64 lastClientId;
    bool running;

signals:
    void started(quint16 port);
    void stopped();
    void newConnnection();
    void message(const QString&);

public slots:
    void start(quint16);
    void stop();

private slots:
    void onNewConnection();
    void onSocketDisconnected();
    void onBinaryMessage(const QByteArray&);
    void castMessage(WMessage*);
    void castClientNickUpdated(quint64, const QString&);
    void castSocketDisconnected(quint64);
    void changeNick(WNickRequest*);
    void sendClientsList(Client*);
};

#endif // SERVERCORE_H
