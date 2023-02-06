#ifndef OR_GATE_TEST
#define OR_GATE_TEST

#include<iostream>
#include<string.h>
#include<chrono>

#include "ComponentCounter.h"

#include "Or.h"
#include "TestFunctions.h"

void orGateTest(int& successes, int& failures, int64_t& timeTaken, ComponentsCounter* componentCounter, bool silentSuccessLog = true){
    Or* orGate = new Or();
    int success = 0;
    int fail = 0;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    TEST<std::string>("Initialization Or gate no arguments test", orGate->toString(), "0", success, fail, silentSuccessLog);

    delete orGate;
    bool input[Or::getInputSize()] = {0,1};
    orGate = new Or(input);
    TEST<std::string>("Initialization Or gate set test", orGate->toString(), "1", success, fail, silentSuccessLog);

    TEST<bool>("Get Or gate test", orGate->get(), 1, success, fail, silentSuccessLog);

    orGate->set(1, 1);
    TEST<bool>("Set Or gate index or bool value test", orGate->get(), 1, success, fail, silentSuccessLog);

    input[0] = 0;
    orGate->set(input);
    TEST<bool>("Set Or gate values set test", orGate->get(), 1, success, fail, silentSuccessLog);

    TEST<int>("Count test", Or::getCount(), 1, success, fail, silentSuccessLog);

    for(int i = 0; i < Or::getTruthTableRowsCount(); i++){
        auto array = Or::getTruthTableInput(i);
        orGate->set(array);
        TEST<bool>("Truth table Or gate test", orGate->get(), Or::getTruthTableOutput(i), success, fail, true);
        delete [] array;
    }

    componentCounter->addCount();

    delete orGate;

    end_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count(); 
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count(); 

    printTestBenchmark(success, fail, (end - start));
    successes += success;
    failures += fail;
    timeTaken += (end - start);
}

#endif