#ifndef WNICKREQUEST_H
#define WNICKREQUEST_H

#include <QString>
#include <QDataStream>
#include "wevent.h"

class WNickRequest : public WEvent
{
public:
    WNickRequest();
    WNickRequest(QString nick_p, quint64 password_p, quint64 senderId_p);

    QString getNick() const;
    quint64 getPassword() const;

protected:
    QDataStream& serialize(QDataStream&) const;
    QDataStream& deserialize(QDataStream&);

private:
    QString nick;
    quint64 password;
};

#endif // WNICKREQUEST_H
