#include<iostream>
#include<string.h>

#include "LoggingUtility.h"
#include "TimeResolution.h"

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
#include "Clear8BitTest.h"
#include "Inverter8BitTest.h"
#include "And8BitTest.h"
#include "Or8BitTest.h"

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

    printTestHeader("Clear8Bit Test");
    clear8BitTest(success, fail, timeTaken);

    printTestHeader("Inverter8Bit Test");
    inverter8BitTest(success, fail, timeTaken);

    printTestHeader("And8Bit Test");
    and8BitTest(success, fail, timeTaken);

    printTestHeader("And8Bit Test");
    or8BitTest(success, fail, timeTaken);

    printTestHeader("Test Results");
    printTestBenchmark(success, fail, timeTaken, TimeFormat::SECONDS);
    return 0;
}