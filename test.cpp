#include<iostream>
#include<string.h>

#include "LoggingUtility.h"
#include "TimeResolution.h"
#include "ComponentCounter.h"

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
#include "Xor8BitTest.h"
#include "Mux2X1Test.h"

int main(){

    int success = 0;
    int fail = 0;
    int64_t timeTaken = 0;

    ComponentsCounter* componentCounter = new ComponentsCounter();

    printTestHeader("InputArray Test");
    InputArrayTest(success, fail, timeTaken);

    printTestHeader("Converters Test");
    convertersTest(success, fail, timeTaken);

    printTestHeader("Input Generator Test");
    inputGeneratorTest(success, fail, timeTaken);

    printTestHeader("NotGate Test");
    notGateTest(success, fail, timeTaken, componentCounter);

    printTestHeader("AndGate Test");
    andGateTest(success, fail, timeTaken, componentCounter);

    printTestHeader("OrGate Test");
    orGateTest(success, fail, timeTaken, componentCounter);

    printTestHeader("XorGate Test");
    xorGateTest(success, fail, timeTaken, componentCounter);

    printTestHeader("NandGate Test");
    nandGateTest(success, fail, timeTaken, componentCounter);

    printTestHeader("NorGate Test");
    norGateTest(success, fail, timeTaken, componentCounter);

    printTestHeader("XnorGate Test");
    xnorGateTest(success, fail, timeTaken, componentCounter);

    printTestHeader("Clear8Bit Test");
    clear8BitTest(success, fail, timeTaken, componentCounter);

    printTestHeader("Inverter8Bit Test");
    inverter8BitTest(success, fail, timeTaken, componentCounter);

    printTestHeader("And8Bit Test");
    and8BitTest(success, fail, timeTaken, componentCounter);

    printTestHeader("Or8Bit Test");
    or8BitTest(success, fail, timeTaken, componentCounter);

    printTestHeader("Xor8Bit Test");
    xor8BitTest(success, fail, timeTaken, componentCounter);

    printTestHeader("Mux2X1 Test");
    mux2X1Test(success, fail, timeTaken, componentCounter);

    printTestHeader("Test Results");
    printTestBenchmark(success, fail, timeTaken, TimeFormat::SECONDS);

    printTestHeader("Gates and components created during run");
    componentCounter->print();

    delete componentCounter;
    return 0;
}