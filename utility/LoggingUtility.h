#ifndef LOGGING_UTILITY
#define LOGGING_UTILITY

void printTestHeader(std::string headerName){
    std::cout<< "\033[1;35m ========================================\033[0m\n";
    std::cout<< "\033[1;35m ========== " << headerName << " ==========\033[0m\n";
    std::cout<< "\033[1;35m ========================================\033[0m\n";
}

void printTestBenchmark(int successCount, int failureCount, auto timeTaken){
    std::cout<< "Successes: " << successCount <<", Failures: " << failureCount << " in " << timeTaken << " micoseconds\n";
}

#endif