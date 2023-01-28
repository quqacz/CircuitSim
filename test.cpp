#include<iostream>
#include<string.h>

#include "InputArrayUtilityTest.h"
#include "TestFunctions.h"
#include "NotGateTest.h"
#include "AndGateTest.h"
#include "OrGateTest.h"
#include "XorGateTest.h"

void printTestHeader(std::string headerName){
    std::cout<< "\033[1;35m ========================================\033[0m\n";
    std::cout<< "\033[1;35m ========== " << headerName << " ==========\033[0m\n";
    std::cout<< "\033[1;35m ========================================\033[0m\n";
}

int main(){
    printTestHeader("InputArrayUtilityTest");
    inputArrayUtilityTest();

    printTestHeader("NotGateTest");
    notGateTest();

    printTestHeader("AndGateTest");
    andGateTest();

    printTestHeader("OrGateTest");
    orGateTest();

    printTestHeader("XorGateTest");
    xorGateTest();
    return 0;
}