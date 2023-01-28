#ifndef NOT_GATE_TEST
#define NOT_GATE_TEST

#include<iostream>
#include<string.h>

#include "Not.h"
#include "TestFunctions.h"

void notGateTest(){
    Not* notGate = new Not();

    TEST<std::string>("Initialization Not gate no arguments test", notGate->toString(), "1");

    notGate = new Not(1);
    TEST<std::string>("Initialization Not gate logical value test", notGate->toString(), "0");

    bool input[Not::getInputSize()] = {0};
    notGate = new Not(input);
    TEST<std::string>("Initialization Not gate set test", notGate->toString(), "1");

    TEST<bool>("Get Not gate test", notGate->get(), 1);

    notGate->set(1);
    TEST<bool>("Set Not gate bool value test", notGate->get(), 0);

    notGate->set(0, 0);
    TEST<bool>("Set Not gate index and bool value test", notGate->get(), 1);

    input[0] = 1;
    notGate->set(input);
    TEST<bool>("Set Not gate values set test", notGate->get(), 0);

    delete notGate;
}

#endif