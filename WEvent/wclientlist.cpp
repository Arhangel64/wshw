#include "wclientlist.h"

WClientList::WClientList():
    WEvent(WEvent::tWClientList)
{
}

QDataStream& WClientList::serialize(QDataStream & ds) const
{
    WEvent::serialize(ds) << modified << removed;
    return ds;
}

QDataStream& WClientList::deserialize(QDataStream & ds)
{
    WEvent::deserialize(ds) >> modified >> removed;
    return ds;
}

void WClientList::pushModified(quint64 id, const QString &nick)
{
    pushModified(QPair<quint64, QString>(id, nick));
}

void WClientList::pushModified(const QPair<quint64, QString> & pair)
{
    modified.append(pair);
}

void WClientList::pushRemoved(quint64 id)
{
    removed.append(id);
}

QPair<quint64, QString> WClientList::popModified()
{
    return modified.takeLast();
}

quint64 WClientList::popRemoved()
{
    return removed.takeLast();
}

int WClientList::getModifiedSize() const
{
    return modified.size();
}

int WClientList::getRemovedSize() const
{
    return removed.size();
}
