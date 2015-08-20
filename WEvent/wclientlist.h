#ifndef WCLIENTLIST_H
#define WCLIENTLIST_H

#include "wevent.h"

#include <QVector>
#include <QPair>
#include <QString>
#include <QDataStream>

class WClientList : public WEvent
{
public:
    WClientList();

    void pushModified(quint64 id, const QString& nick);
    void pushModified(const QPair<quint64, QString>& pair);
    void pushRemoved(quint64);

    QPair<quint64, QString> popModified();
    quint64 popRemoved();

    int getModifiedSize() const;
    int getRemovedSize() const;

protected:
    QDataStream& serialize(QDataStream&) const;
    QDataStream& deserialize(QDataStream&);


private:
    QVector< QPair< quint64, QString > > modified;
    QVector<quint64> removed;

};

#endif // WCLIENTLIST_H
