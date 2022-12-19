#include "Or.h"

Or::Or()
{
}

Or::Or(Connector* i0, Connector* i1) : LogicGate(i0, i1)
{
}

Or::~Or()
{
    i0 = nullptr;
    i1 = nullptr;
    o0 = nullptr;
}

bool Or::getO0()
{
    return i0->getState() && i1->getState();
}