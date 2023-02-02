#ifndef XOR_GATE_TEST
#define XOR_GATE_TEST

#include<iostream>
#include<string.h>
#include<chrono>

#include "Xor.h"
#include "TestFunctions.h"

void xorGateTest(int& successes, int& failures, int64_t& timeTaken, bool silentSuccessLog = true){
    Xor* xorGate = new Xor();
    int success = 0;
    int fail = 0;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    TEST<std::string>("Initialization Xor gate no arguments test", xorGate->toString(), "0", success, fail, silentSuccessLog);

    delete xorGate;
    bool input[Xor::getInputSize()] = {0,1};
    xorGate = new Xor(input);
    TEST<std::string>("Initialization Xor gate set test", xorGate->toString(), "1", success, fail, silentSuccessLog);

    TEST<bool>("Get Xor gate test", xorGate->get(), 1, success, fail, silentSuccessLog);

    xorGate->set(0, 1);
    TEST<bool>("Set Xor gate index and bool value test", xorGate->get(), 0, success, fail, silentSuccessLog);

    input[0] = 1;
    input[1] = 0;
    xorGate->set(input);
    TEST<bool>("Set Xor gate values set test", xorGate->get(), 1, success, fail, silentSuccessLog);

    TEST<int>("Count test", Xor::getCount(), 1, success, fail, silentSuccessLog);

    for(int i = 0; i < Xor::getTruthTableRowsCount(); i++){
        auto array = Xor::getTruthTableInput(i);
        xorGate->set(array);
        TEST<bool>("Truth table And gate test", xorGate->get(), Xor::getTruthTableOutput(i), success, fail, true);
        delete [] array;
    }

    delete xorGate;

    end_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count(); 
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count(); 

    printTestBenchmark(success, fail, (end - start));
    successes += success;
    failures += fail;
    timeTaken += (end - start);
}

#endif