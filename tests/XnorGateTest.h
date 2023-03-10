#ifndef XNOR_GATE_TEST
#define XNOR_GATE_TEST

#include<iostream>
#include<string.h>
#include<chrono>

#include "ComponentCounter.h"
#include "TestSettings.h"

#include "Xnor.h"
#include "TestFunctions.h"

void xnorGateTest(TestSettings* testSettings, ComponentsCounter* componentCounter){
    Xnor* xnorGate = new Xnor();
    int success = 0;
    int fail = 0;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    TEST<std::string>("Initialization Xnor gate no arguments test", xnorGate->toString(), "1", success, fail, testSettings->silentSuccessLog);

    delete xnorGate;
    bool input[Xnor::getInputSize()] = {0,1};
    xnorGate = new Xnor(input);
    TEST<std::string>("Initialization Xnor gate set test", xnorGate->toString(), "0", success, fail, testSettings->silentSuccessLog);

    TEST<bool>("Get Xnor gate test", xnorGate->get(), 0, success, fail, testSettings->silentSuccessLog);

    xnorGate->set(0, 1);
    TEST<bool>("Set Xnor gate index and bool value test", xnorGate->get(), 1, success, fail, testSettings->silentSuccessLog);

    input[0] = 1;
    input[1] = 0;
    xnorGate->set(input);
    TEST<bool>("Set Xnor gate values set test", xnorGate->get(), 0, success, fail, testSettings->silentSuccessLog);

    TEST<int>("Count test", Xnor::getCount(), 1, success, fail, testSettings->silentSuccessLog);

    for(int i = 0; i < Xnor::getTruthTableRowsCount(); i++){
        auto array = Xnor::getTruthTableInput(i);
        xnorGate->set(array);
        TEST<bool>("Truth table Xnor gate test", xnorGate->get(), Xnor::getTruthTableOutput(i), success, fail, true);
        delete [] array;
    }

    componentCounter->addCount();

    delete xnorGate;

    end_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count(); 
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count(); 

    printTestBenchmark(success, fail, (end - start));
    testSettings->successes += success;
    testSettings->failures += fail;
    testSettings->timeTaken += (end - start);
}

#endif