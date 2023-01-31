#ifndef INPUT_GENERATOR_TEST
#define INPUT_GENERATOR_TEST

#include<iostream>
#include<chrono>

#include "InputGenerator.h"
#include "TestFunctions.h"

// bool testData[8][3] = {
//     {0, 0, 0},
//     {0, 0, 1},
//     {0, 1, 0},
//     {0, 1, 1},
//     {1, 0, 0},
//     {1, 0, 1},
//     {1, 1, 0},
//     {1, 1, 1},
// };

void inputGeneratorTest(int& successes, int& failures, int64_t& timeTaken){
    int success = 0;
    int fail = 0;

    InputGenerator* generatedInput = new InputGenerator(8, 3);

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    for(auto i = 0; i < 8; i++){
        TEST_ARRAY<bool*>("Input generator test", generatedInput->get(i), testData[i], 3, success, fail, false);
    }

    end_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count(); 
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count(); 

    delete generatedInput;

    printTestBenchmark(success, fail, (end - start));
    successes += success;
    failures += fail;
    timeTaken += (end - start);
}

#endif