#ifndef INPUT_ARRAY_UTILITY_TEST
#define INPUT_ARRAY_UTILITY_TEST

#include<iostream>
#include<string.h>
#include<chrono>

#include "InputArray.h"
#include "TestFunctions.h"
#include "LoggingUtility.h"

void InputArrayTest(int& successes, int& failures, int64_t& timeTaken){
    unsigned short length = 3;
    bool inputArray[length] = {1,0,1};
    int success = 0;
    int fail = 0;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    InputArray* input = new InputArray(inputArray, length);
    TEST<std::string>("Initialization InputArray test", input->toString(), "101", success, fail);

    input = new InputArray(length);
    TEST<std::string>("Initialization empty InputArray test", input->toString(), "000", success, fail);

    TEST<int>("Size InputArray test", input->size(), length, success, fail);

    TEST<bool>("Get InputArray test", input->get(0), 0, success, fail);

    inputArray[0] = inputArray[1] = inputArray[2] = 0;
    TEST_ARRAY<bool*>("GetValues InputArray test", input->getValues(), inputArray, length, success, fail);

    char inputChars[length] ={'0','0','0'};
    TEST_ARRAY<char*>("GetChars InputArray test", input->getChars(), inputChars, length, success, fail); 

    input->set(0, 1);
    TEST<std::string>("Set one InputArray test", input->toString(), "100", success, fail);

    inputArray[0] = inputArray[2] = 1;
    input->set(inputArray);
    TEST<std::string>("Set all InputArray test", input->toString(), "101", success, fail);

    input->setNot();
    TEST<std::string>("SetNot InputArray test", input->toString(), "010", success, fail);

    inputArray[0] = 1;
    inputArray[1] = 1;
    inputArray[2] = 0;
    input->setAnd(inputArray);
    TEST<std::string>("SetAnd InputArray test", input->toString(), "010", success, fail);

    inputArray[0] = 1;
    inputArray[1] = 1;
    inputArray[2] = 0;
    input->setOr(inputArray);
    TEST<std::string>("SetOr InputArray test", input->toString(), "110", success, fail);

    inputArray[0] = 1;
    inputArray[1] = 0;
    inputArray[2] = 0;
    input->setXor(inputArray);
    TEST<std::string>("SetXor InputArray test", input->toString(), "010", success, fail);

    delete input;

    end_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count(); 
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count(); 

    printTestBenchmark(success, fail, (end - start));
    successes += success;
    failures += fail;
    timeTaken += (end - start);
}

#endif