#ifndef XOR_GATE_TEST
#define XOR_GATE_TEST

#include<iostream>
#include<string.h>

#include "Xor.h"
#include "TestFunctions.h"

void xorGateTest(){
    Xor* xorGate = new Xor();

    TEST<std::string>("Initialization Xor gate no arguments test", xorGate->toString(), "0");

    bool input[Xor::getInputSize()] = {0,1};
    xorGate = new Xor(input);
    TEST<std::string>("Initialization Xor gate set test", xorGate->toString(), "1");

    TEST<bool>("Get Xor gate test", xorGate->get(), 1);

    xorGate->set(0, 1);
    TEST<bool>("Set Xor gate bool value test", xorGate->get(), 0);

    xorGate->set(1, 1);
    TEST<bool>("Set Xor gate index and bool value test", xorGate->get(), 0);

    input[0] = 1;
    input[1] = 0;
    xorGate->set(input);
    TEST<bool>("Set Xor gate values set test", xorGate->get(), 1);

    delete xorGate;
}

#endif