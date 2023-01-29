#ifndef NOT_GATE_TEST
#define NOT_GATE_TEST

#include<iostream>
#include<string.h>
#include<chrono>

#include "Not.h"
#include "TestFunctions.h"

void notGateTest(int& successes, int& failures, int64_t& timeTaken){
    Not* notGate = new Not();
    int success = 0;
    int fail = 0;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    TEST<std::string>("Initialization Not gate no arguments test", notGate->toString(), "1", success, fail);

    delete notGate;
    notGate = new Not(1);
    TEST<std::string>("Initialization Not gate logical value test", notGate->toString(), "0", success, fail);

    bool input[Not::getInputSize()] = {0};
    delete notGate;
    notGate = new Not(input);
    TEST<std::string>("Initialization Not gate set test", notGate->toString(), "1", success, fail);

    TEST<bool>("Get Not gate test", notGate->get(), 1, success, fail);

    notGate->set(1);
    TEST<bool>("Set Not gate bool value test", notGate->get(), 0, success, fail);

    notGate->set(0, 0);
    TEST<bool>("Set Not gate index and bool value test", notGate->get(), 1, success, fail);

    input[0] = 1;
    notGate->set(input);
    TEST<bool>("Set Not gate values set test", notGate->get(), 0, success, fail);

    TEST<int>("Count test", Not::getCount(), 1, success, fail);

    delete notGate;

    end_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count(); 
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count(); 

    printTestBenchmark(success, fail, (end - start));
    successes += success;
    failures += fail;
    timeTaken += (end - start);
}

#endif