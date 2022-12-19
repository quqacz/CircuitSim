#ifndef LOGICGATE_H
#define LOGICGATE_H

#include "Connector.h"

class LogicGate : Component
{

protected:
    Connector* i0 = nullptr;
    Connector* i1 = nullptr;
    Connector* o0 = nullptr;
public:
    LogicGate(/* args */);
    LogicGate(Connector*);
    LogicGate(Connector*, Connector*);
    LogicGate(Connector*, Connector*, Connector*);
    ~LogicGate();
    void plugI0(Connector*);
    void plugI1(Connector*);
    void plugO0(Connector*);
    virtual bool getO0() const = 0;
};

#endif