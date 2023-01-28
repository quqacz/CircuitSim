#ifndef OR_GATE
#define OR_GATE

#include "InputArrayUtility.h"

class Or{
    static const int inputSize = 2;
    static const int outputSize = 1;
    static int count;

    InputArrayUtility* input;
    InputArrayUtility* output;

    void propagate(){
        output->set(0, input->get(0) || input->get(1));
    }

    public:

    Or(){
        input = new InputArrayUtility(inputSize);
        output = new InputArrayUtility(outputSize);
        propagate();
    }

    Or(bool inputValue[]){
        input = new InputArrayUtility(inputValue, inputSize);
        output = new InputArrayUtility(outputSize);
        propagate();
    }

    ~Or(){
        delete input;
        delete output;
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

    static int getInputSize(){
        return Or::inputSize;
    }

    static int getOutputSize(){
        return Or::outputSize;
    }
};

#endif