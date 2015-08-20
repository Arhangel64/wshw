#include "wnickresponse.h"

WNickResponse::WNickResponse():
    WEvent(WEvent::tWNickResponse)
{
}

WNickResponse::WNickResponse(bool accepted_p, quint64 senderId_p, const QString &fallback_p):
    WEvent(senderId_p, WEvent::tWNickResponse),
    accepted(accepted_p),
    fallback(fallback_p)
{
}

QString WNickResponse::getFallback() const
{
    return fallback;
}
void WNickResponse::setFallback(const QString& fbk)
{
    fallback = fbk;
}

bool WNickResponse::isAccepted() const
{
    return accepted;
}

void WNickResponse::setAccepted(bool acpt)
{
    accepted = acpt;
}

QDataStream& WNickResponse::serialize(QDataStream &ds) const
{
    WEvent::serialize(ds) << accepted << fallback;
    return ds;
}

QDataStream& WNickResponse::deserialize(QDataStream &ds)
{
    WEvent::deserialize(ds) >> accepted >> fallback;
    return ds;
}
