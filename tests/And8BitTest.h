#ifndef AND8BIT_TEST
#define AND8BIT_TEST

#include<iostream>
#include<chrono>

#include "And8Bit.h"
#include "TestFunctions.h"
#include "InputGenerator.h"
#include "InputArray.h"
#include "LoggingUtility.h"

void and8BitTest(int& successes, int& failures, int64_t& timeTaken, bool silentSuccessLog = true){
    int success = 0;
    int fail = 0;

    const int rows = 256;
    const int columns = 8; 

    And8Bit* and8Bit = new And8Bit();

    InputGenerator* input = new InputGenerator(rows, columns);

    InputArray* output = new InputArray(columns);

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    for(auto i = 1; i < rows; i+=2){
        for(auto j = 0; j < rows; j+= 3){
            and8Bit->setA(input->get(i));
            and8Bit->setB(input->get(j));
            output->set(input->get(i));
            output->setAnd(input->get(j));
            TEST_ARRAY<bool*>("And8Bit test", and8Bit->get(), output->getValues(), columns, success, fail, silentSuccessLog);

        }
    }
    end_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count(); 
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count(); 

    delete and8Bit;
    delete input;
    delete output;

    printTestBenchmark(success, fail, (end - start));
    successes += success;
    failures += fail;
    timeTaken += (end - start);
}

#endif