#ifndef WSETID_H
#define WSETID_H

#include "wevent.h"

class WSetId : public WEvent
{
public:
    WSetId(quint64);
    WSetId();
};

#endif // WSETID_H
