#include<iostream>
#include<string.h>

#include "LoggingUtility.h"

#include "InputArrayTest.h"
#include "ConvertersTest.h"
#include "Converters.h"
#include "TestFunctions.h"
#include "NotGateTest.h"
#include "AndGateTest.h"
#include "OrGateTest.h"
#include "XorGateTest.h"
#include "NandGateTest.h"
#include "NorGateTest.h"
#include "XnorGateTest.h"
#include "InputGeneratorTest.h"

int main(){

    int success = 0;
    int fail = 0;
    int64_t timeTaken = 0;

    printTestHeader("InputArray Test");
    InputArrayTest(success, fail, timeTaken);

    printTestHeader("Converters Test");
    convertersTest(success, fail, timeTaken);

    printTestHeader("Input Generator Test");
    inputGeneratorTest(success, fail, timeTaken);

    printTestHeader("NotGate Test");
    notGateTest(success, fail, timeTaken);

    printTestHeader("AndGate Test");
    andGateTest(success, fail, timeTaken);

    printTestHeader("OrGate Test");
    orGateTest(success, fail, timeTaken);

    printTestHeader("XorGate Test");
    xorGateTest(success, fail, timeTaken);

    printTestHeader("NandGate Test");
    nandGateTest(success, fail, timeTaken);

    printTestHeader("NorGate Test");
    norGateTest(success, fail, timeTaken);

    printTestHeader("XnorGate Test");
    xnorGateTest(success, fail, timeTaken);

    printTestHeader("Test Results");
    printTestBenchmark(success, fail, timeTaken);
    return 0;
}