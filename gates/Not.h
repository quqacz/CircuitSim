#ifndef NOT_GATE
#define NOT_GATE

#include "InputArray.h"
#include "Gate.h"

// gate implements !A

class Not : public Gate{
    static const int inputSize = 1;
    static const int outputSize = 1;
    static int count;

    static const int truthTableRows = 2;
    static const int truthTableInputCollumns = 1;

    static constexpr bool truthTableInput[truthTableRows][truthTableInputCollumns]= {
        {0}, {1}
    };

    static constexpr bool truthTableOutput[truthTableRows] = {
        1, 0
    };

    InputArray* input;
    InputArray* output;

    void propagate(){
        output->set(0, !input->get(0));
    }

    public:

    Not(){
        input = new InputArray(inputSize);
        output = new InputArray(outputSize);
        propagate();

        Not::count ++;
    }

    Not(bool inputValue[]){
        input = new InputArray(inputValue, inputSize);
        output = new InputArray(outputSize);
        propagate();

        Not::count ++;
    }

    Not(bool inputValue){
        input = new InputArray(inputSize);
        output = new InputArray(outputSize);
        input->set(0, inputValue);
        propagate();

        Not::count ++;
    }

    ~Not(){
        delete input;
        delete output;

        Not::count --;
    }

    bool get(){
        return output->get(0);
    }

    void set(bool value){
        input->set(0, value);
        propagate();
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
        return Not::count;
    }

    static int getInputSize(){
        return Not::inputSize;
    }

    static int getOutputSize(){
        return Not::outputSize;
    }

    
    static int getTruthTableRowsCount(){
        return Not::truthTableRows;
    }

    static bool* getTruthTableInput(int index){
        if(index < 0 || index > Not::truthTableRows){
            throw std::invalid_argument("Requested invalid index");
        }

        bool* entry = new bool(Not::truthTableInputCollumns);
        for(int i = 0; i < Not::truthTableInputCollumns; i++){
            entry[i] = Not::truthTableInput[index][i];
        }

        return entry;
    }

    static bool getTruthTableOutput(int index){
        if(index < 0 || index > Not::truthTableRows){
            throw std::invalid_argument("Requested invalid index");
        }
        return Not::truthTableOutput[index];
    }

    static void printTruthTable(){
        for(int i = 0; i < Not::truthTableRows; i++){
            for(int j = 0; j < Not::truthTableInputCollumns; j++){
                std::cout<< Not::truthTableInput[i][j] << " ";
            }
            std::cout<< "|" << Not::truthTableOutput[i] << std::endl; 
        }
    }
};

int Not::count = 0;

constexpr bool Not::truthTableInput[Not::truthTableRows][Not::truthTableInputCollumns];
constexpr bool Not::truthTableOutput[Not::truthTableRows];

#endif