#ifndef OR_GATE
#define OR_GATE

#include "InputArrayUtility.h"

// gate implements A + B

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

        Or::count ++;
    }

    Or(bool inputValue[]){
        input = new InputArrayUtility(inputValue, inputSize);
        output = new InputArrayUtility(outputSize);
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
};

int Or::count = 0;

#endif