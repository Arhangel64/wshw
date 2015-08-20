#include "wmessage.h"

WMessage::WMessage(const QString& msg_p, quint64 senderId_p):
    WEvent(senderId_p, WEvent::tWMessage)
{
    msg = msg_p;
}

WMessage::WMessage():
    WEvent(WEvent::tWMessage)
{
}

QString WMessage::getMessage() const
{
    return msg;
}

QDataStream& WMessage::serialize(QDataStream& out) const
{
    WEvent::serialize(out) << msg;
    return out;
}

QDataStream& WMessage::deserialize(QDataStream& in)
{
    WEvent::deserialize(in) >> msg;
    return in;
}
