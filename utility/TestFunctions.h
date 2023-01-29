#ifndef TEST_FUNCTIONS
#define TEST_FUNCTIONS

#include<iostream>
#include<string.h>

template<typename T> void TEST(std::string testName, T output, T expectedOutput){
    if(output == expectedOutput){
        std::cout<< "\033[1;32m(pass)\t" << testName << "\033[0m\n";
    }else{
        std::cout<< "\033[1;31m(fail)\t" << testName << "; expected: " << expectedOutput << ", provided: " << output << "\033[0m\n";
    }
}

template<typename T> void TEST_ARRAY(std::string testName, T output, T expectedOutput, int size){
    for(auto i = 0; i < size; i++){
        if(output[i] != expectedOutput[i]){
            std::cout<< "\033[1;31m(fail)\t" << testName << "; expected: " << expectedOutput << ", provided: " << output << "\033[0m\n";
            return;
        }
    }
    std::cout<< "\033[1;32m(pass)\t" << testName << " pass \033[0m\n";
}

template<typename T> void TEST(std::string testName, T output, T expectedOutput, int& success, int& fail, bool silent = false){
    if(output == expectedOutput){
        if(!silent){
            std::cout<< "\033[1;32m(pass)\t" << testName << "\033[0m\n";
        }
        success += 1;
    }else{
        std::cout<< "\033[1;31m(fail)\t" << testName << "; expected: " << expectedOutput << ", provided: " << output << "\033[0m\n";
        fail += 1;
    }
}

template<typename T> void TEST_ARRAY(std::string testName, T output, T expectedOutput, int size, int& success, int& fail){
    for(auto i = 0; i < size; i++){
        if(output[i] != expectedOutput[i]){
            std::cout<< "\033[1;31m(fail)\t" << testName << "; expected: " << expectedOutput << ", provided: " << output << "\033[0m\n";
            fail += 1;
            return;
        }
    }
    std::cout<< "\033[1;32m(pass)\t" << testName << "\033[0m\n";
    success += 1;
}

#endif