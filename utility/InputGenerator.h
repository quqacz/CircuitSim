#ifndef INPUT_GENERATOR
#define INPUT_GENERATOR

#include<iostream>

#include "Converters.h"

class InputGenerator
{
private:
    bool* values;
    int rowsCount;
    int columnsCount;

    void generate(){
        for(auto i = 0; i < this->rowsCount; i++){
            auto res = decymalToBinary(i, this->columnsCount);
            set(i, res);
        }
    }

    void set(int row, bool values[]){
        if(row < 0 || row > this->rowsCount){
            throw new std::runtime_error("Index out of bound");
        }

        int startIndex = row * this->columnsCount;

        for(auto i = 0; i < this->columnsCount; i++){
            this->values[startIndex + i] = values[i];
        }
    }
    
public:

    InputGenerator(int rows, int columns){
        this->columnsCount = columns;
        this->rowsCount = rows;

        this->values = new bool(this->rowsCount * this->columnsCount);
        generate();
    }

    ~InputGenerator(){
        delete [] this->values;
    } 

    bool* get(int row){
        if(row < 0 || row > this->rowsCount){
            throw new std::runtime_error("Index out of bound");
        }

        bool* values = new bool(this->columnsCount);

        const int startIndex = row * this->columnsCount;
        for(int i = 0; i < this->columnsCount; i++){
            values[i] = this->values[startIndex + i];
        }

        return values;
    }
};

#endif