#ifndef XNOR_GATE_TEST
#define XNOR_GATE_TEST

#include<iostream>
#include<string.h>

#include "Xnor.h"
#include "TestFunctions.h"

void xnorGateTest(){
    Xnor* xnorGate = new Xnor();

    TEST<std::string>("Initialization Xnor gate no arguments test", xnorGate->toString(), "1");

    bool input[Xnor::getInputSize()] = {0,1};
    xnorGate = new Xnor(input);
    TEST<std::string>("Initialization Xnor gate set test", xnorGate->toString(), "0");

    TEST<bool>("Get Xnor gate test", xnorGate->get(), 0);

    xnorGate->set(0, 1);
    TEST<bool>("Set Xnor gate index and bool value test", xnorGate->get(), 1);

    input[0] = 1;
    input[1] = 0;
    xnorGate->set(input);
    TEST<bool>("Set Xnor gate values set test", xnorGate->get(), 0);

    delete xnorGate;
}

#endif