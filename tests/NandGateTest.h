#ifndef NAND_GATE_TEST
#define NAND_GATE_TEST

#include<iostream>
#include<string.h>
#include<chrono>

#include "ComponentCounter.h"
#include "TestSettings.h"

#include "Nand.h"
#include "TestFunctions.h"

void nandGateTest(TestSettings* testSettings, ComponentsCounter* componentCounter){
    Nand* nandGate = new Nand();
    int success = 0;
    int fail = 0;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    TEST<std::string>("Initialization Nand gate no arguments test", nandGate->toString(), "1", success, fail, testSettings->silentSuccessLog);

    delete nandGate;
    bool input[Nand::getInputSize()] = {0,1};
    nandGate = new Nand(input);
    TEST<std::string>("Initialization Nand gate set test", nandGate->toString(), "1", success, fail, testSettings->silentSuccessLog);

    TEST<bool>("Get Nand gate test", nandGate->get(), 1, success, fail, testSettings->silentSuccessLog);

    nandGate->set(0, 1);
    TEST<bool>("Set Nand gate index and bool value test", nandGate->get(), 0, success, fail, testSettings->silentSuccessLog);

    input[0] = 1;
    input[1] = 0;
    nandGate->set(input);
    TEST<bool>("Set Nand gate values set test", nandGate->get(), 1, success, fail, testSettings->silentSuccessLog);

    TEST<int>("Count test", Nand::getCount(), 1, success, fail, testSettings->silentSuccessLog);

    for(int i = 0; i < Nand::getTruthTableRowsCount(); i++){
        auto array = Nand::getTruthTableInput(i);
        nandGate->set(array);
        TEST<bool>("Truth table Nand gate test", nandGate->get(), Nand::getTruthTableOutput(i), success, fail, true);
        delete [] array;
    }

    componentCounter->addCount();

    delete nandGate;

    end_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count(); 
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count(); 

    printTestBenchmark(success, fail, (end - start));
    testSettings->successes += success;
    testSettings->failures += fail;
    testSettings->timeTaken += (end - start);
}

#endif