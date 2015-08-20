#ifndef NICKMODEL_H
#define NICKMODEL_H

#include <QString>

class NickModel
{
public:
    NickModel();
    NickModel(const QString&, quint64);

    void connect(quint64);
    void disconnect();

    quint64 getConnectionId() const;
    bool passwordMatch(quint64) const;
    bool isConnected() const;
    QString getNick() const;

private:
    QString nick;
    quint64 pass;
    bool connected;
    quint64 connectionId;
};

#endif // NICKMODEL_H
