#ifndef TEST_SETTINGS
#define TEST_SETTINGS

#include<iostream>

class TestSettings {
    public:
    int successes = 0;
    int failures = 0;
    int64_t timeTaken = 0;
    bool silentSuccessLog = true;
};

#endif