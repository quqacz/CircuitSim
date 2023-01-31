#ifndef AND_GATE
#define AND_GATE

#include<iostream>

#include "InputArray.h"
#include "Gate.h"

// gate implements ( AB )

class And : public Gate{
    static const int inputSize = 2;
    static const int outputSize = 1;
    static int count;

    static const int truthTableRows = 4;
    static const int truthTableInputCollumns = 2;

    static constexpr bool truthTableInput[truthTableRows][truthTableInputCollumns]= {
        {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };

    static constexpr bool truthTableOutput[truthTableRows] = {
        0, 0, 0, 1
    };

    InputArray* input;
    InputArray* output;

    void propagate(){
        output->set(0, input->get(0) && input->get(1));
    }

    public:

    And(){
        input = new InputArray(inputSize);
        output = new InputArray(outputSize);
        propagate();

        And::count ++;
    }

    And(bool inputValue[]){
        input = new InputArray(inputValue, inputSize);
        output = new InputArray(outputSize);
        propagate();

        And::count ++;
    }

    ~And(){
        And::count --;
    }

    bool get(){
        return output->get(0);
    }

    void set(int index, bool value){
        if(index < 0 || index > inputSize){
            throw std::invalid_argument("Requested invalid index");
        }
        input->set(index, value);
        propagate();
    }

    void set(bool values[]){
        input->set(values);
        propagate();
    }

    std::string toString(){
        return output->toString();
    }

    static int getCount(){
        return And::count;
    }

    static int getInputSize(){
        return And::inputSize;
    }

    static int getOutputSize(){
        return And::outputSize;
    }

    static int getTruthTableRowsCount(){
        return And::truthTableRows;
    }

    static bool* getTruthTableInput(int index){
        if(index < 0 || index > And::truthTableRows){
            throw std::invalid_argument("Requested invalid index");
        }

        bool* entry = new bool(And::truthTableInputCollumns);
        for(int i = 0; i < And::truthTableInputCollumns; i++){
            entry[i] = And::truthTableInput[index][i];
        }

        return entry;
    }

    static bool getTruthTableOutput(int index){
        if(index < 0 || index > And::truthTableRows){
            throw std::invalid_argument("Requested invalid index");
        }
        return And::truthTableOutput[index];
    }

    static void printTruthTable(){
        for(int i = 0; i < And::truthTableRows; i++){
            for(int j = 0; j < And::truthTableInputCollumns; j++){
                std::cout<< And::truthTableInput[i][j] << " ";
            }
            std::cout<< "|" << And::truthTableOutput[i] << std::endl; 
        }
    }
};

int And::count = 0;

constexpr bool And::truthTableInput[And::truthTableRows][And::truthTableInputCollumns];
constexpr bool And::truthTableOutput[And::truthTableRows];

#endif