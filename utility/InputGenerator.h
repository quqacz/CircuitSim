#ifndef INPUT_GENERATOR
#define INPUT_GENERATOR

#include<iostream>

#include "Converters.h"

class InputGenerator
{
private:
    int rowsCount;
    int columnsCount;

    bool* generate(int i){
        return decymalToBinary(i, this->columnsCount);
    }
    
public:

    InputGenerator(int rows, int columns){
        this->columnsCount = columns;
        this->rowsCount = rows;
    }

    ~InputGenerator(){} 

    bool* get(int row){
        if(row < 0 || row > this->rowsCount){
            throw new std::runtime_error("Index out of bound");
        }

        return generate(row);
    }
};

#endif