#ifndef NOR_GATE_TEST
#define NOR_GATE_TEST

#include<iostream>
#include<string.h>
#include<chrono>

#include "Nor.h"
#include "TestFunctions.h"

void norGateTest(int& successes, int& failures, int64_t& timeTaken){
    Nor* norGate = new Nor();
    int success = 0;
    int fail = 0;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    TEST<std::string>("Initialization Nor gate no arguments test", norGate->toString(), "1", success, fail);

    delete norGate;
    bool input[Nor::getInputSize()] = {0,1};
    norGate = new Nor(input);
    TEST<std::string>("Initialization Nor gate set test", norGate->toString(), "0", success, fail);

    TEST<bool>("Get Nor gate test", norGate->get(), 0, success, fail);

    norGate->set(1, 1);
    TEST<bool>("Set Nor gate index nor bool value test", norGate->get(), 0, success, fail);

    input[0] = 1;
    input[1] = 0;
    norGate->set(input);
    TEST<bool>("Set Nor gate values set test", norGate->get(), 0, success, fail);

    TEST<int>("Count test", Nor::getCount(), 1, success, fail);

    for(int i = 0; i < Nor::getTruthTableRowsCount(); i++){
        auto array = Nor::getTruthTableInput(i);
        norGate->set(array);
        TEST<bool>("Truth table Nor gate test", norGate->get(), Nor::getTruthTableOutput(i), success, fail, true);
        delete [] array;
    }

    delete norGate;

    end_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count(); 
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count(); 

    printTestBenchmark(success, fail, (end - start));
    successes += success;
    failures += fail;
    timeTaken += (end - start);
}

#endif