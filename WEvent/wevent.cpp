#include <QDataStream>
#include <QByteArray>
#include <QBuffer>
#include "wevent.h"
#include "wmessage.h"
#include "wsetid.h"
#include "wnickrequest.h"
#include "wnickresponse.h"
#include "wclientlist.h"
#include <iostream>

using std::cout;
using std::endl;

WEvent::WEvent(quint64 senderId_p, typeId eventType_p):
    eventType(eventType_p),
    senderId(senderId_p)
{
}

WEvent::WEvent(typeId eventType_p):
    eventType(eventType_p),
    senderId(0)
{
}

WEvent::typeId WEvent::getEventType() const
{
    return eventType;
}

quint64 WEvent::getSenderId() const
{
    return senderId;
}

QDataStream & WEvent::serialize(QDataStream& out) const
{
    out << eventType << senderId;
    return out;
}

QDataStream & WEvent::deserialize(QDataStream& in)
{
    in >> senderId;
    return in;
}

WEvent* WEvent::createFromQByteArray(const QByteArray & ba)
{
    QDataStream ds(ba);
    WEvent *ret;
    int id;
    ds >> id;
    switch (id)
    {
    case WEvent::tWEvent:
        ret = new WEvent();
        break;
    case WEvent::tWMessage:
        ret = new WMessage();
        break;
    case WEvent::tWSetId:
        ret = new WSetId();
        break;
    case WEvent::tWNickRequest:
        ret = new WNickRequest();
        break;
    case WEvent::tWNickResponse:
        ret = new WNickResponse();
        break;
    case WEvent::tWClientList:
        ret = new WClientList();
        break;
    }
    ret->deserialize(ds);
    return ret;
}

QByteArray WEvent::serializeToQByteArray(WEvent* ev)
{
    QByteArray ba;
    QBuffer bufo(&ba);
    bufo.open(QIODevice::WriteOnly);
    QDataStream ds(&bufo);
    ev->serialize(ds);
    bufo.close();
    return ba;
}
