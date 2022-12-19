#include "LogicGate.h"

LogicGate::LogicGate()
{
}

LogicGate::LogicGate(Connector* i0){
    this->i0 = i0;
}

LogicGate::LogicGate(Connector* i0, Connector* i1){
    this->i0 = i0;
    this->i1 = i1;
}

LogicGate::LogicGate(Connector* i0, Connector* i1, Connector* o0){
    this->LogicGate::LogicGate(i0, i1);
    this->o0 = o0;
}

LogicGate::~LogicGate(){
    this->i0->unplug(this);
    this->i1->unplug(this);
    this->o0->unplug(this);

    this->i0 = nullptr;
    this->i1 = nullptr;
    this->o0 = nullptr;
}

void LogicGate::plugI0(Connector * i0)
{
    this->i0 = i0;
}

void LogicGate::plugI1(Connector * i1)
{
    this->i1 = i1;
}

void LogicGate::plugO0(Connector* o0){
    this->o0 = o0;
}