#include "wnickrequest.h"

WNickRequest::WNickRequest():
    WEvent(WEvent::tWNickRequest)
{
}

WNickRequest::WNickRequest(QString nick_p, quint64 password_p, quint64 senderId_p):
    WEvent(senderId_p, WEvent::tWNickRequest),
    nick(nick_p),
    password(password_p)
{
}

quint64 WNickRequest::getPassword() const
{
    return password;
}

QString WNickRequest::getNick() const
{
    return nick;
}

QDataStream& WNickRequest::serialize(QDataStream& ds) const
{
    WEvent::serialize(ds) << nick << password;
    return ds;
}
QDataStream& WNickRequest::deserialize(QDataStream& ds)
{
    WEvent::deserialize(ds) >> nick >> password;
    return ds;
}
