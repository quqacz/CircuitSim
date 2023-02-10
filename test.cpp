#include<iostream>
#include<string.h>

#include "LoggingUtility.h"
#include "TimeResolution.h"
#include "ComponentCounter.h"
#include "TestSettings.h"

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
    TestSettings* testSettings = new TestSettings();

    printTestHeader("InputArray Test");
    InputArrayTest(testSettings);

    printTestHeader("Converters Test");
    convertersTest(testSettings);

    printTestHeader("Input Generator Test");
    inputGeneratorTest(testSettings);

    printTestHeader("NotGate Test");
    notGateTest(testSettings, componentCounter);

    printTestHeader("AndGate Test");
    andGateTest(testSettings, componentCounter);

    printTestHeader("OrGate Test");
    orGateTest(testSettings, componentCounter);

    printTestHeader("XorGate Test");
    xorGateTest(testSettings, componentCounter);

    printTestHeader("NandGate Test");
    nandGateTest(testSettings, componentCounter);

    printTestHeader("NorGate Test");
    norGateTest(testSettings, componentCounter);

    printTestHeader("XnorGate Test");
    xnorGateTest(testSettings, componentCounter);

    printTestHeader("Clear8Bit Test");
    clear8BitTest(testSettings, componentCounter);

    printTestHeader("Inverter8Bit Test");
    inverter8BitTest(testSettings, componentCounter);

    printTestHeader("And8Bit Test");
    and8BitTest(testSettings, componentCounter);

    printTestHeader("Or8Bit Test");
    or8BitTest(testSettings, componentCounter);

    printTestHeader("Xor8Bit Test");
    xor8BitTest(testSettings, componentCounter);

    printTestHeader("Mux2X1 Test");
    mux2X1Test(testSettings, componentCounter);
                                    
    printTestHeader("Test Results");
    printTestBenchmark(testSettings->successes, testSettings->failures, testSettings->timeTaken, TimeFormat::SECONDS);

    printTestHeader("Gates and components created during run");
    componentCounter->print();

    delete componentCounter;
    return 0;
}