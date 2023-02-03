#ifndef XOR8BIT_TEST
#define XOR8BIT_TEST

#include<iostream>
#include<chrono>

#include "Xor8Bit.h"
#include "TestFunctions.h"
#include "InputGenerator.h"
#include "InputArray.h"
#include "LoggingUtility.h"

void xor8BitTest(int& successes, int& failures, int64_t& timeTaken, bool silentSuccessLog = true){
    int success = 0;
    int fail = 0;

    const int rows = 256;
    const int columns = 8; 

    Xor8Bit* xor8Bit = new Xor8Bit();

    InputGenerator* input = new InputGenerator(rows, columns);

    InputArray* output = new InputArray(columns);

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    for(auto i = 1; i < rows; i+=2){
        for(auto j = 0; j < rows; j+= 3){
            xor8Bit->setA(input->get(i));
            xor8Bit->setB(input->get(j));
            output->set(input->get(i));
            output->setXor(input->get(j));
            TEST_ARRAY<bool*>("Xor8Bit test", xor8Bit->get(), output->getValues(), columns, success, fail, silentSuccessLog);

        }
    }
    end_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count(); 
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count(); 

    delete xor8Bit;
    delete input;
    delete output;

    printTestBenchmark(success, fail, (end - start));
    successes += success;
    failures += fail;
    timeTaken += (end - start);
}

#endif