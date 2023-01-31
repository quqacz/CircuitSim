#ifndef OR_GATE
#define OR_GATE

#include "InputArray.h"
#include "Gate.h"

// gate implements A + B

class Or : public Gate{
    static const int inputSize = 2;
    static const int outputSize = 1;
    static int count;

    static const int truthTableRows = 4;
    static const int truthTableInputCollumns = 2;

    static constexpr bool truthTableInput[truthTableRows][truthTableInputCollumns]= {
        {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };

    static constexpr bool truthTableOutput[truthTableRows] = {
        0, 1, 1, 1
    };

    InputArray* input;
    InputArray* output;

    void propagate(){
        output->set(0, input->get(0) || input->get(1));
    }

    public:

    Or(){
        input = new InputArray(inputSize);
        output = new InputArray(outputSize);
        propagate();

        Or::count ++;
    }

    Or(bool inputValue[]){
        input = new InputArray(inputValue, inputSize);
        output = new InputArray(outputSize);
        propagate();

        Or::count ++;
    }

    ~Or(){
        delete input;
        delete output;

        Or::count --;
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
        return Or::count;
    }

    static int getInputSize(){
        return Or::inputSize;
    }

    static int getOutputSize(){
        return Or::outputSize;
    }

    static int getTruthTableRowsCount(){
        return Or::truthTableRows;
    }

    static bool* getTruthTableInput(int index){
        if(index < 0 || index > Or::truthTableRows){
            throw std::invalid_argument("Requested invalid index");
        }

        bool* entry = new bool(Or::truthTableInputCollumns);
        for(int i = 0; i < Or::truthTableInputCollumns; i++){
            entry[i] = Or::truthTableInput[index][i];
        }

        return entry;
    }

    static bool getTruthTableOutput(int index){
        if(index < 0 || index > Or::truthTableRows){
            throw std::invalid_argument("Requested invalid index");
        }
        return Or::truthTableOutput[index];
    }

    static void printTruthTable(){
        for(int i = 0; i < Or::truthTableRows; i++){
            for(int j = 0; j < Or::truthTableInputCollumns; j++){
                std::cout<< Or::truthTableInput[i][j] << " ";
            }
            std::cout<< "|" << Or::truthTableOutput[i] << std::endl; 
        }
    }
};

int Or::count = 0;

constexpr bool Or::truthTableInput[Or::truthTableRows][Or::truthTableInputCollumns];
constexpr bool Or::truthTableOutput[Or::truthTableRows];

#endif