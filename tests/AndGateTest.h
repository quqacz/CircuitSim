#ifndef AND_GATE_TEST
#define AND_GATE_TEST

#include<iostream>
#include<string.h>

#include "And.h"
#include "TestFunctions.h"

void andGateTest(){
    And* andGate = new And();

    TEST<std::string>("Initialization And gate no arguments test", andGate->toString(), "0");

    bool input[And::getInputSize()] = {0,1};
    andGate = new And(input);
    TEST<std::string>("Initialization And gate set test", andGate->toString(), "0");

    TEST<bool>("Get And gate test", andGate->get(), 0);

    andGate->set(0, 1);
    TEST<bool>("Set And gate index and bool value test", andGate->get(), 1);

    input[0] = 0;
    andGate->set(input);
    TEST<bool>("Set And gate values set test", andGate->get(), 0);

    delete andGate;
}

#endif