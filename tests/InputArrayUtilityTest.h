#ifndef INPUT_ARRAY_UTILITY_TEST
#define INPUT_ARRAY_UTILITY_TEST

#include<iostream>
#include<string.h>

#include "InputArrayUtility.h"
#include "TestFunctions.h"

void inputArrayUtilityTest(){
    unsigned short length = 3;
    bool inputArray[length] = {1,0,1};

    InputArrayUtility* input = new InputArrayUtility(inputArray, length);
    TEST<std::string>("Initialization InputArrayUtility", input->toString(), "101");

    input = new InputArrayUtility(length);
    TEST<std::string>("Initialization empty InputArrayUtility test", input->toString(), "000");

    TEST<int>("Size InputArrayUtility test", input->size(), length);

    TEST<bool>("Get InputArrayUtility test", input->get(0), 0);

    inputArray[0] = inputArray[1] = inputArray[2] = 0;
    TEST_ARRAY<bool*>("GetValues InputArrayUtility test", input->getValues(), inputArray, length);

    char inputChars[length] ={'0','0','0'};
    TEST_ARRAY<char*>("GetChars InputArrayUtility test", input->getChars(), inputChars, length); 

    input->set(0, 1);
    TEST<std::string>("Set one InputArrayUtility test", input->toString(), "100");

    inputArray[0] = inputArray[2] = 1;
    input->set(inputArray);
    TEST<std::string>("Set all InputArrayUtility test", input->toString(), "101");

    input->setNot();
    TEST<std::string>("SetNot InputArrayUtility test", input->toString(), "010");

    inputArray[0] = 1;
    inputArray[1] = 1;
    inputArray[2] = 0;
    input->setAnd(inputArray);
    TEST<std::string>("SetAnd InputArrayUtility test", input->toString(), "010");

    inputArray[0] = 1;
    inputArray[1] = 1;
    inputArray[2] = 0;
    input->setOr(inputArray);
    TEST<std::string>("SetOr InputArrayUtility test", input->toString(), "110");

    inputArray[0] = 1;
    inputArray[1] = 0;
    inputArray[2] = 0;
    input->setXor(inputArray);
    TEST<std::string>("SetXor InputArrayUtility test", input->toString(), "010");
    delete input;
}

#endif