#ifndef TIME_RESOLUTION
#define TIME_RESOLUTION

#include<iostream>

enum TimeFormat { MICROSECONDS, MILISECONDS, SECONDS, MINUTES };

std::string formatedTime(int64_t time, TimeFormat format){
    std::string output = "";
    long double outputTime = (long double)time;
    for(auto i = 0; i < format; i++){
        if(i != TimeFormat::MINUTES){
            outputTime /= 1000;
        }else{
            outputTime /= 60;
        }
    }

    switch (format)
    {
    case TimeFormat::MICROSECONDS:
        output = std::to_string(outputTime) + " microseconds";
        break;
    case TimeFormat::MILISECONDS:
        output = std::to_string(outputTime) + " miliseconds";
        break;
    case TimeFormat::SECONDS:
        output = std::to_string(outputTime) + " seconds";
        break;
    default:
        output = std::to_string(outputTime) + " minutes";
        break;
    }

    return output;
}

#endif