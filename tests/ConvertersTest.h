#ifndef CONVERTERS_TEST
#define CONVERTERS_TEST

#include<iostream>
#include<chrono>

#include "Converters.h"
#include "TestFunctions.h"

bool testData[8][3] = {
    {0, 0, 0},
    {0, 0, 1},
    {0, 1, 0},
    {0, 1, 1},
    {1, 0, 0},
    {1, 0, 1},
    {1, 1, 0},
    {1, 1, 1},
};

void convertersTest(int& successes, int& failures, int64_t& timeTaken){
    int success = 0;
    int fail = 0;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    bool* testInput;

    for(auto i = 0; i < 8; i++){
        testInput = decymalToBinary(i, 3);
        TEST_ARRAY<bool*>("Converter decimal to binary test", testInput, testData[i], 3, success, fail, true);
    }

    end_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count(); 
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count(); 

    delete [] testInput;

    printTestBenchmark(success, fail, (end - start));
    successes += success;
    failures += fail;
    timeTaken += (end - start);
}

#endif