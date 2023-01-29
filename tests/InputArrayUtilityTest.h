#ifndef INPUT_ARRAY_UTILITY_TEST
#define INPUT_ARRAY_UTILITY_TEST

#include<iostream>
#include<string.h>
#include<chrono>

#include "InputArrayUtility.h"
#include "TestFunctions.h"
#include "LoggingUtility.h"

void inputArrayUtilityTest(int& successes, int& failures, int64_t& timeTaken){
    unsigned short length = 3;
    bool inputArray[length] = {1,0,1};
    int success = 0;
    int fail = 0;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    InputArrayUtility* input = new InputArrayUtility(inputArray, length);
    TEST<std::string>("Initialization InputArrayUtility test", input->toString(), "101", success, fail);

    input = new InputArrayUtility(length);
    TEST<std::string>("Initialization empty InputArrayUtility test", input->toString(), "000", success, fail);

    TEST<int>("Size InputArrayUtility test", input->size(), length, success, fail);

    TEST<bool>("Get InputArrayUtility test", input->get(0), 0, success, fail);

    inputArray[0] = inputArray[1] = inputArray[2] = 0;
    TEST_ARRAY<bool*>("GetValues InputArrayUtility test", input->getValues(), inputArray, length, success, fail);

    char inputChars[length] ={'0','0','0'};
    TEST_ARRAY<char*>("GetChars InputArrayUtility test", input->getChars(), inputChars, length, success, fail); 

    input->set(0, 1);
    TEST<std::string>("Set one InputArrayUtility test", input->toString(), "100", success, fail);

    inputArray[0] = inputArray[2] = 1;
    input->set(inputArray);
    TEST<std::string>("Set all InputArrayUtility test", input->toString(), "101", success, fail);

    input->setNot();
    TEST<std::string>("SetNot InputArrayUtility test", input->toString(), "010", success, fail);

    inputArray[0] = 1;
    inputArray[1] = 1;
    inputArray[2] = 0;
    input->setAnd(inputArray);
    TEST<std::string>("SetAnd InputArrayUtility test", input->toString(), "010", success, fail);

    inputArray[0] = 1;
    inputArray[1] = 1;
    inputArray[2] = 0;
    input->setOr(inputArray);
    TEST<std::string>("SetOr InputArrayUtility test", input->toString(), "110", success, fail);

    inputArray[0] = 1;
    inputArray[1] = 0;
    inputArray[2] = 0;
    input->setXor(inputArray);
    TEST<std::string>("SetXor InputArrayUtility test", input->toString(), "010", success, fail);

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