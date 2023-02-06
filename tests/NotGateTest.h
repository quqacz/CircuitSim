#ifndef NOT_GATE_TEST
#define NOT_GATE_TEST

#include<iostream>
#include<string.h>
#include<chrono>

#include "ComponentCounter.h"

#include "Not.h"
#include "TestFunctions.h"

void notGateTest(int& successes, int& failures, int64_t& timeTaken, ComponentsCounter* componentCounter, bool silentSuccessLog = true){
    Not* notGate = new Not();
    int success = 0;
    int fail = 0;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    TEST<std::string>("Initialization Not gate no arguments test", notGate->toString(), "1", success, fail, silentSuccessLog);

    delete notGate;
    notGate = new Not(1);
    TEST<std::string>("Initialization Not gate logical value test", notGate->toString(), "0", success, fail, silentSuccessLog);

    bool input[Not::getInputSize()] = {0};
    delete notGate;
    notGate = new Not(input);
    TEST<std::string>("Initialization Not gate set test", notGate->toString(), "1", success, fail, silentSuccessLog);

    TEST<bool>("Get Not gate test", notGate->get(), 1, success, fail, silentSuccessLog);

    notGate->set(1);
    TEST<bool>("Set Not gate bool value test", notGate->get(), 0, success, fail, silentSuccessLog);

    notGate->set(0, 0);
    TEST<bool>("Set Not gate index and bool value test", notGate->get(), 1, success, fail, silentSuccessLog);

    input[0] = 1;
    notGate->set(input);
    TEST<bool>("Set Not gate values set test", notGate->get(), 0, success, fail, silentSuccessLog);

    TEST<int>("Count test", Not::getCount(), 1, success, fail, silentSuccessLog);

    for(int i = 0; i < Not::getTruthTableRowsCount(); i++){
        auto array = Not::getTruthTableInput(i);
        notGate->set(array);
        TEST<bool>("Truth table Not gate test", notGate->get(), Not::getTruthTableOutput(i), success, fail, true);
        delete [] array;
    }

    componentCounter->addCount();

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