#ifndef NAND_GATE_TEST
#define NAND_GATE_TEST

#include<iostream>
#include<string.h>

#include "Nand.h"
#include "TestFunctions.h"

void nandGateTest(){
    Nand* nandGate = new Nand();

    TEST<std::string>("Initialization Nand gate no arguments test", nandGate->toString(), "1");

    bool input[Nand::getInputSize()] = {0,1};
    nandGate = new Nand(input);
    TEST<std::string>("Initialization Nand gate set test", nandGate->toString(), "1");

    TEST<bool>("Get Nand gate test", nandGate->get(), 1);

    nandGate->set(0, 1);
    TEST<bool>("Set Nand gate index and bool value test", nandGate->get(), 0);

    input[0] = 1;
    input[1] = 0;
    nandGate->set(input);
    TEST<bool>("Set Nand gate values set test", nandGate->get(), 1);

    delete nandGate;
}

#endif