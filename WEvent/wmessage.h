#ifndef WMESSAGE_H
#define WMESSAGE_H

#include <QString>
#include <QDataStream>
#include "wevent.h"

class WMessage : public WEvent
{
public:
    WMessage(const QString&, quint64);
    WMessage();

    QString getMessage() const;

protected:
    QDataStream& serialize(QDataStream&) const;
    QDataStream& deserialize(QDataStream&);

private:
    QString msg;
};

#endif // WMESSAGE_H
