#ifndef NOR_GATE_TEST
#define NOR_GATE_TEST

#include<iostream>
#include<string.h>

#include "Nor.h"
#include "TestFunctions.h"

void norGateTest(){
    Nor* norGate = new Nor();

    TEST<std::string>("Initialization Nor gate no arguments test", norGate->toString(), "1");

    bool input[Nor::getInputSize()] = {0,1};
    norGate = new Nor(input);
    TEST<std::string>("Initialization Nor gate set test", norGate->toString(), "0");

    TEST<bool>("Get Nor gate test", norGate->get(), 0);

    norGate->set(1, 1);
    TEST<bool>("Set Nor gate index and bool value test", norGate->get(), 0);

    input[0] = 1;
    input[1] = 0;
    norGate->set(input);
    TEST<bool>("Set Nor gate values set test", norGate->get(), 0);

    delete norGate;
}

#endif