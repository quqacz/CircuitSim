#ifndef MUX2X1_TEST
#define MUX2X1_TEST

#include<iostream>
#include<chrono>

#include "ComponentCounter.h"
#include "TestSettings.h"

#include "Mux2X1.h"
#include "TestFunctions.h"
#include "InputGenerator.h"
#include "InputArray.h"
#include "LoggingUtility.h"

void mux2X1Test(TestSettings* testSettings, ComponentsCounter* componentCounter){
    int success = 0;
    int fail = 0;

    const int rows = 2;
    const int columns = 1; 

    Mux2X1* mux2X1 = new Mux2X1();
    mux2X1->setS(false);

    InputGenerator* input = new InputGenerator(rows, columns);

    InputArray* output = new InputArray(columns);

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    for(auto i = 0; i < rows; i++){
        for(auto j = 0; j < rows; j++){
            auto a = input->get(i);
            auto b = input->get(j);
            mux2X1->setA(a);
            mux2X1->setB(b);
            output->set(a);
            TEST_ARRAY<bool*>("Mux2X1 test", mux2X1->get(), output->getValues(), columns, success, fail, testSettings->silentSuccessLog);

        }   
    }
    mux2X1->setS(true);

    for(auto i = 0; i < rows; i++){
        for(auto j = 0; j < rows; j++){
            auto a = input->get(i);
            auto b = input->get(j);
            mux2X1->setA(a);
            mux2X1->setB(b);
            output->set(b);
            TEST_ARRAY<bool*>("Mux2X1 test", mux2X1->get(), output->getValues(), columns, success, fail, testSettings->silentSuccessLog);

        }   
    }    

    end_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count(); 
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count(); 

    componentCounter->addCount();

    delete mux2X1;
    delete input;
    delete output;

    printTestBenchmark(success, fail, (end - start));
    testSettings->successes += success;
    testSettings->failures += fail;
    testSettings->timeTaken += (end - start);
}

#endif