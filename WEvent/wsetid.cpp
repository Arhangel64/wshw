#include "wsetid.h"

WSetId::WSetId(quint64 id_p):
    WEvent(id_p, WEvent::tWSetId)
{

}

WSetId::WSetId():
    WEvent(WEvent::tWSetId)
{

}

