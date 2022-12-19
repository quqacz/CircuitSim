#include "And.h"

And::And()
{
}

And::And(Connector* i0, Connector* i1) : LogicGate(i0, i1)
{
}

And::~And()
{
    this->LogicGate::~LogicGate();
}

bool And::getO0()
{
    return i0->getState() && i1->getState();
}
