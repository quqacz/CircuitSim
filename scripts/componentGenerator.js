const fs = require('fs')

const componentName = process.argv[2];
const className = process.argv[3].replace(process.argv[3][0], process.argv[3][0].toUpperCase());

if(!isInputValid(componentName, className)){
    return
}

const componentDefinitionName = componentName.toUpperCase()
const componentTestDefinitionName = `${componentName.toUpperCase()}_TEST`
const testObjectName = className.replace(className[0], className[0].toLowerCase());

const testFileName = "./test.cpp"

const componentFileName = `${className}.h`
const componentTestFileName = `${className}Test.h`

const componentFilePath = `./components/${componentFileName}`
const componentTestFilePath = `./tests/${componentTestFileName}`
const componentCounterFilePath = `./utility/ComponentCounter.h`

const componentTestFunctionName = `${testObjectName}Test`

const componentFile = `#ifndef ${componentDefinitionName}
#define ${componentDefinitionName}

#include<iostream>

#include "InputArray.h"

class ${className} {
    static const int inputSize = 8;
    static const int outputSize = 8;
    static int count;

    InputArray* inputA;
    InputArray* inputB;

    InputArray* output;

    void propagate(){

    }

    void update(){

    }

    public:
    ${className}(){
        inputA = new InputArray(inputSize);
        inputB = new InputArray(inputSize);

        output = new InputArray(outputSize);

        update();
        propagate();

        ${className}::count ++;
    }


    ~${className}(){
        delete inputA;
        delete inputB;

        delete output;

        ${className}::count --;
    }

    bool* get(){
        return output->getValues();
    }

    bool get(int index){
        if(index < 0 || index > outputSize){
            throw std::invalid_argument("Requested invalid index");
        }
        return output->get(index);
    }

    void setA(int index, bool value){
        if(index < 0 || index > inputSize){
            throw std::invalid_argument("Requested invalid index");
        }
        inputA->set(index, value);
        update();
        propagate();
    }

    void setB(int index, bool value){
        if(index < 0 || index > inputSize){
            throw std::invalid_argument("Requested invalid index");
        }
        inputA->set(index, value);
        update();
        propagate();
    }

    void setA(bool values[]){
        inputA->set(values);
        update();
        propagate();
    }

    void setB(bool values[]){
        inputB->set(values);
        update();
        propagate();
    }

    std::string toString(){
        return output->toString();
    }

    static int getCount(){
        return ${className}::count;
    }

    static int getInputSize(){
        return ${className}::inputSize;
    }

    static int getOutputSize(){
        return ${className}::outputSize;
    }
};

int ${className}::count = 0;

#endif`

const testFile = `#ifndef ${componentTestDefinitionName}
#define ${componentTestDefinitionName}

#include<iostream>
#include<chrono>

#include "ComponentCounter.h"
#include "TestSettings.h"

#include "${className}.h"
#include "TestFunctions.h"
#include "LoggingUtility.h"

void ${componentTestFunctionName}(TestSettings* testSettings, ComponentsCounter* componentCounter){
    int success = 0;
    int fail = 0;

    ${className}* ${testObjectName} = new ${className}();

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    start_point = std::chrono::high_resolution_clock::now();

    


    end_point = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count(); 
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count(); 

    componentCounter->addCount();

    delete ${testObjectName};

    printTestBenchmark(success, fail, (end - start));
    testSettings->successes += success;
    testSettings->failures += fail;
    testSettings->timeTaken += (end - start);
}

#endif`

fs.writeFile(componentFilePath, componentFile, (err) => {
     if (err) 
     throw err
    }
)

fs.writeFile(componentTestFilePath, testFile, (err) => {
    if (err) 
    throw err
   }
)

fs.readFile(testFileName, 'utf-8', (err, data)=>{
    if(err){
        console.error(err)
        return
    }
    const includeIndex = data.lastIndexOf(".h\"")
    const includeIndexOffset = 4

    const testFunctionIndex = data.lastIndexOf("componentCounter);")
    const testIndexOffset = 20

    const includePath = `#include "${componentTestFileName}"
    `
    const testFunction = `
    printTestHeader("${className} Test");
    ${componentTestFunctionName}(testSettings, componentCounter);
    `

    const outputFile = data.slice(0, includeIndex + includeIndexOffset) + includePath + data.slice(includeIndex + includeIndexOffset + 2, testFunctionIndex + testIndexOffset) + testFunction + data.slice(testFunctionIndex + testIndexOffset)

    fs.writeFile(testFileName, outputFile, (err) =>{
        if(err){
            console.error(err)
            return
        }
    })
})

fs.readFile(componentCounterFilePath, 'utf-8', (err, data) =>{
    if(err){
        console.error(err)
        return
    }

    const includeIndex = data.lastIndexOf(".h\"")
    const includeIndexOffset = 4

    const createVariableCounterIndex = data.lastIndexOf("0;")
    const createCounterVariableOffset = 2

    const incrementCounterIndex = data.lastIndexOf("Count();")
    const incrementCounterIndexOffset = 8;

    const printCounterIndex = data.lastIndexOf("endl;")
    const printCounterIndexOffset = 6

    const includePath = `#include "${componentFileName}"
    `
    const createCounterVariable = `
    int ${testObjectName} = 0;
    `
    const incrementCounter = `
    \t${testObjectName} += ${className}::getCount();`
    const printComponentCount = `
    \tstd::cout<<"${className} count: " << ${testObjectName} << std::endl;`

    let outputFile = data.slice(0, includeIndex + includeIndexOffset) + includePath

    outputFile += data.slice(includeIndex + includeIndexOffset + 2, createVariableCounterIndex + createCounterVariableOffset) + createCounterVariable
    
    outputFile += data.slice(createVariableCounterIndex + createCounterVariableOffset + 2, incrementCounterIndex + incrementCounterIndexOffset) + incrementCounter
    
    outputFile += data.slice(incrementCounterIndex + incrementCounterIndexOffset, printCounterIndex + printCounterIndexOffset) + printComponentCount
    
    outputFile += data.slice( printCounterIndex + printCounterIndexOffset)

    fs.writeFile(componentCounterFilePath, outputFile, (err) =>{
        if(err){
            console.error(err)
            return
        }
    })

})

function isInputValid(componentName, className){
    const noNoWords = ["alignas", "alignof", "asm", "auto", "bool", "break", "case", "catch", "char", "char16_t", "char32_t", "class", "const", "constexpr", "const_cast", "continue", "decltype", "default", "delete", "double", "do", "dynamic_cast", "else", "enum", "explicit", "export", "extern", "FALSE", "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "nullptr", "operator", "private", "protected", "public", "register", "reinterpret_cast", "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct", "switch", "template", "this", "thread_local", "throw", "TRUE", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while"]

    if(!componentName || !className){
        console.error("Parameters are missing")
        return false
    }

    const regex = /^[a-zA-Z_][0-9a-zA-Z_]*/
    if(!regex.test(componentName) || !regex.test(className)){
        console.error("Bad input fomrting")
        return false
    }

    if(noNoWords.includes(componentName) || noNoWords.includes(className)){
        console.error("Name is a keyword")
        return false
    }
    
    return true
}