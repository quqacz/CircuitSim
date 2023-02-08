#ifndef INPUT_GENERATOR_TEST
#define INPUT_GENERATOR_TEST

#include<iostream>
#include<chrono>

#include "InputGenerator.h"
#include "TestFunctions.h"
#include "TestData.h"

void inputGeneratorTest(TestSettings* testSettings){
    int success = 0;
    int fail = 0;

    InputGenerator* generatedInput = new InputGenerator(8, 3);

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    for(auto i = 0; i < 8; i++){
        TEST_ARRAY<bool*>("Input generator test", generatedInput->get(i), TEST_DATA::testData3B[i], 3, success, fail, testSettings->silentSuccessLog);
    }

    end_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count(); 
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count(); 

    delete generatedInput;

    printTestBenchmark(success, fail, (end - start));
    testSettings->successes += success;
    testSettings->failures += fail;
    testSettings->timeTaken += (end - start);
}

#endif