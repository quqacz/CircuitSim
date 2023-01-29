#ifndef GATE
#define GATE

#include "InputArrayUtility.h"

class Gate{
    public:
    Gate(){}
    ~Gate(){}
    virtual bool get() = 0;
    virtual void set(bool values[]) = 0;
};

#endif