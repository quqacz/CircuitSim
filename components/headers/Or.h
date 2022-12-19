#ifndef OR_H
#define OR_H

#include "LogicGate.h"
#include "Connector.h"

class Or : LogicGate
{
public:
    Or(/* args */);
    Or(Connector*, Connector*);
    ~Or();
    bool getO0();
};

#endif