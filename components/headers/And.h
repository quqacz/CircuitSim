#ifndef AND_H
#define AND_H

#include "Connector.h"
#include "LogicGate.h"

class And : LogicGate
{
public:
    And(/* args */);
    And(Connector*, Connector*);
    ~And();
    bool getO0();
};


#endif