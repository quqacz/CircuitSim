#ifndef OR_GATE_TEST
#define OR_GATE_TEST

#include<iostream>
#include<string.h>

#include "Or.h"
#include "TestFunctions.h"

void orGateTest(){
    Or* orGate = new Or();

    TEST<std::string>("Initialization Or gate no arguments test", orGate->toString(), "0");

    bool input[Or::getInputSize()] = {0,1};
    orGate = new Or(input);
    TEST<std::string>("Initialization Or gate set test", orGate->toString(), "1");

    TEST<bool>("Get Or gate test", orGate->get(), 1);

    orGate->set(0, 1);
    TEST<bool>("Set Or gate bool value test", orGate->get(), 1);

    orGate->set(1, 1);
    TEST<bool>("Set Or gate index and bool value test", orGate->get(), 1);

    input[0] = 0;
    orGate->set(input);
    TEST<bool>("Set Or gate values set test", orGate->get(), 1);

    delete orGate;
}

#endif