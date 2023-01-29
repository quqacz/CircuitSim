#include<iostream>
#include<string.h>

#include "LoggingUtility.h"

#include "InputArrayUtilityTest.h"
#include "TestFunctions.h"
#include "NotGateTest.h"
#include "AndGateTest.h"
#include "OrGateTest.h"
#include "XorGateTest.h"
#include "NandGateTest.h"
#include "NorGateTest.h"
#include "XnorGateTest.h"

int main(){

    int success = 0;
    int fail = 0;
    int64_t timeTaken = 0;

    printTestHeader("InputArrayUtilityTest");
    inputArrayUtilityTest(success, fail, timeTaken);

    printTestHeader("NotGateTest");
    notGateTest(success, fail, timeTaken);

    printTestHeader("AndGateTest");
    andGateTest(success, fail, timeTaken);

    printTestHeader("OrGateTest");
    orGateTest(success, fail, timeTaken);

    printTestHeader("XorGateTest");
    xorGateTest(success, fail, timeTaken);

    printTestHeader("NandGateTest");
    nandGateTest(success, fail, timeTaken);

    printTestHeader("NorGateTest");
    norGateTest(success, fail, timeTaken);

    printTestHeader("XnorGateTest");
    xnorGateTest(success, fail, timeTaken);

    printTestHeader("Test Results");
    printTestBenchmark(success, fail, timeTaken);
    return 0;
}