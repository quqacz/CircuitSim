#ifndef INVERTER8BIT_TEST
#define INVERTER8BIT_TEST

#include<iostream>
#include<chrono>

#include "ComponentCounter.h"

#include "Inverter8Bit.h"
#include "TestFunctions.h"
#include "InputGenerator.h"
#include "InputArray.h"
#include "LoggingUtility.h"

void inverter8BitTest(int& successes, int& failures, int64_t& timeTaken, ComponentsCounter* componentCounter, bool silentSuccessLog = true){
    int success = 0;
    int fail = 0;

    const int rows = 256;
    const int columns = 8; 

    Inverter8Bit* inverter = new Inverter8Bit();

    InputGenerator* input = new InputGenerator(rows, columns);

    InputArray* output = new InputArray(columns);

    inverter->setInv(true);

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    for(auto i = 0; i < rows; i++){
        inverter->set(input->get(i));
        output->set(input->get(i));
        output->setNot();
        TEST_ARRAY<bool*>("Inverter8Bit test", inverter->get(), output->getValues(), columns, success, fail, silentSuccessLog);
    }

    inverter->setInv(false);

    for(auto i = 0; i < rows; i++){
        inverter->set(input->get(i));
        output->set(input->get(i));
        TEST_ARRAY<bool*>("Inverter8Bit test", inverter->get(), input->get(i), columns, success, fail, silentSuccessLog);
    }       

    end_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count(); 
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count(); 

    componentCounter->addCount();

    delete inverter;
    delete input;
    delete output;

    printTestBenchmark(success, fail, (end - start));
    successes += success;
    failures += fail;
    timeTaken += (end - start);
}

#endif