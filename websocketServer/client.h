#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QWebSocket>
#include <QString>
#include <QByteArray>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(quint64 id_p, QWebSocket* socket_p, QObject *parent = 0);
    Client(const Client&);
    Client& operator=(const Client&);
    ~Client();

    quint64 getId() const;
    QString getName() const;
    void setName(const QString&);
    void sendBinaryMessage(const QByteArray&);

private:
    QWebSocket* socket;
    quint64 id;
    QString name;

    void connectSocket();

signals:
    void disconnected();
    void binaryMessageReceived(const QByteArray&);

public slots:
};

#endif // CLIENT_H
