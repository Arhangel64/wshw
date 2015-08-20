#ifndef CLIENTCORE_H
#define CLIENTCORE_H

#include <QObject>
#include <QWebSocket>
#include <QString>

#include "wevent.h"
#include "wmessage.h"
#include "wsetid.h"
#include "wnickrequest.h"
#include "wnickresponse.h"
#include "wclientlist.h"
#include "clientlistmodel.h"

class ClientCore : public QObject
{
    Q_OBJECT
public:
    explicit ClientCore(QObject *parent = 0);
    
    enum State 
    {
        Disconnected,
        Connecting,
        Handshaking,
        Connected,
        Disconnecting
    };
    
    void setServerAddress(const QString&);
    void setServerPort(quint16);
    void setNick(const QString&, quint64);
    QString getServerAddress() const;
    quint16 getServerPort() const;
    QString getNick() const;
    quint64 getPass() const;
    bool isConnected() const;
    ClientListModel* getClienListModel();
    
private:
    QWebSocket *socket;
    quint64 clientId;
    ClientListModel nics;
    QString serverAddress;
    quint16 serverPort;
    QString nick;
    quint64 passHash;
    bool connected;
    bool reconnection;

    void initSocket();
    void requestNick();

signals:
    void message(const QString&, const QString&);
    void info(const QString&);
    void state(ClientCore::State);
    void nickChanged(const QString&);
    void nickDenied();

public slots:
    void start();
    void stop(bool soft = false);
    void reconnect();
    void sendMessage(const QString&);

private slots:
    void socketOpened();
    void socketConnected();
    void socketDisconnected();
    void socketError();
    void receivedId(WSetId*);
    void receivedMessage(WMessage*);
    void receivedNick(WNickResponse*);
    void receivedClientList(WClientList*);
    void socketBinaryMessageReceived(const QByteArray&);
};

#endif // CLIENTCORE_H
