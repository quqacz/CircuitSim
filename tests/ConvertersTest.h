#ifndef CONVERTERS_TEST
#define CONVERTERS_TEST

#include<iostream>
#include<chrono>

#include "Converters.h"
#include "TestFunctions.h"
#include "TestData.h"

void convertersTest(TestSettings* testSettings){
    int success = 0;
    int fail = 0;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    bool* testInput;

    for(auto i = 0; i < 8; i++){
        testInput = decymalToBinary(i, 3);
        TEST_ARRAY<bool*>("Converter decimal to binary test", testInput, testData3B[i], 3, success, fail, true);
    }

    end_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count(); 
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count(); 

    delete [] testInput;

    printTestBenchmark(success, fail, (end - start));
    testSettings->successes += success;
    testSettings->failures += fail;
    testSettings->timeTaken += (end - start);
}

#endif