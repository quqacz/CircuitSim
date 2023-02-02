#ifndef AND_GATE_TEST
#define AND_GATE_TEST

#include<iostream>
#include<string.h>
#include<chrono>

#include "And.h"
#include "TestFunctions.h"

void andGateTest(int& successes, int& failures, int64_t& timeTaken, bool silentSuccessLog = true){
    And* andGate = new And();
    int success = 0;
    int fail = 0;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    TEST<std::string>("Initialization And gate no arguments test", andGate->toString(), "0", success, fail, silentSuccessLog);

    delete andGate;
    bool input[And::getInputSize()] = {0,1};
    andGate = new And(input);
    TEST<std::string>("Initialization And gate set test", andGate->toString(), "0", success, fail, silentSuccessLog);

    TEST<bool>("Get And gate test", andGate->get(), 0, success, fail, silentSuccessLog);

    andGate->set(0, 1);
    TEST<bool>("Set And gate index and bool value test", andGate->get(), 1, success, fail, silentSuccessLog);

    input[0] = 0;
    andGate->set(input);
    TEST<bool>("Set And gate values set test", andGate->get(), 0, success, fail, silentSuccessLog);

    TEST<int>("Count test", And::getCount(), 1, success, fail, silentSuccessLog);
  
    for(int i = 0; i < And::getTruthTableRowsCount(); i++){
        auto array = And::getTruthTableInput(i);
        andGate->set(array);
        TEST<bool>("Truth table And gate test", andGate->get(), And::getTruthTableOutput(i), success, fail, true);
        delete [] array;
    }

    delete andGate;

    end_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count(); 
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count(); 

    printTestBenchmark(success, fail, (end - start));
    successes += success;
    failures += fail;
    timeTaken += (end - start);
}

#endif