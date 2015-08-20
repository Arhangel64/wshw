#ifndef WNICKRESPONSE_H
#define WNICKRESPONSE_H

#include "wevent.h"
#include <QString>
#include <QDataStream>

class WNickResponse : public WEvent
{
public:
    WNickResponse();
    WNickResponse(bool accepted_p, quint64 senderId_p, const QString& fallback_p = "");

    bool isAccepted() const;
    void setAccepted(bool);
    QString getFallback() const;
    void setFallback(const QString&);

protected:
    QDataStream& serialize(QDataStream&) const;
    QDataStream& deserialize(QDataStream&);

private:
    bool accepted;
    QString fallback;
};

#endif // WNICKRESPONSE_H
