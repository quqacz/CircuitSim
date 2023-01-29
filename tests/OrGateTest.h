#ifndef OR_GATE_TEST
#define OR_GATE_TEST

#include<iostream>
#include<string.h>
#include<chrono>

#include "Or.h"
#include "TestFunctions.h"

void orGateTest(int& successes, int& failures, int64_t& timeTaken){
    Or* orGate = new Or();
    int success = 0;
    int fail = 0;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    TEST<std::string>("Initialization Or gate no arguments test", orGate->toString(), "0", success, fail);

    delete orGate;
    bool input[Or::getInputSize()] = {0,1};
    orGate = new Or(input);
    TEST<std::string>("Initialization Or gate set test", orGate->toString(), "1", success, fail);

    TEST<bool>("Get Or gate test", orGate->get(), 1, success, fail);

    orGate->set(1, 1);
    TEST<bool>("Set Or gate index and bool value test", orGate->get(), 1, success, fail);

    input[0] = 0;
    orGate->set(input);
    TEST<bool>("Set Or gate values set test", orGate->get(), 1, success, fail);

    TEST<int>("Count test", Or::getCount(), 1, success, fail);

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