#ifndef LOGGING_UTILITY
#define LOGGING_UTILITY

#include "TimeResolution.h"

void printTestHeader(std::string headerName){
    std::cout<< "\033[1;35m ========================================\033[0m\n";
    std::cout<< "\033[1;35m ========== " << headerName << " ==========\033[0m\n";
    std::cout<< "\033[1;35m ========================================\033[0m\n";
}

void printTestBenchmark(int successCount, int failureCount, auto timeTaken, TimeFormat format = TimeFormat::MICROSECONDS){
    std::cout<< "Successes: " << successCount <<", Failures: " << failureCount << " in " << formatedTime(timeTaken, format) <<std::endl;
}

void printArray(bool array[], int length, char separator = '\0'){
    for(int i = 0; i < length; i++){
        std::cout<< array[i];
    }
    std::cout << std::endl;
}

#endif