#ifndef NOT_GATE
#define NOT_GATE

#include "InputArrayUtility.h"

// gate implements !A

class Not{
    static const int inputSize = 1;
    static const int outputSize = 1;
    static int count;

    InputArrayUtility* input;
    InputArrayUtility* output;

    void propagate(){
        output->set(0, !input->get(0));
    }

    public:

    Not(){
        input = new InputArrayUtility(inputSize);
        output = new InputArrayUtility(outputSize);
        propagate();
    }

    Not(bool inputValue[]){
        input = new InputArrayUtility(inputValue, inputSize);
        output = new InputArrayUtility(outputSize);
        propagate();
    }

    Not(bool inputValue){
        input = new InputArrayUtility(inputSize);
        output = new InputArrayUtility(outputSize);
        input->set(0, inputValue);
        propagate();
    }

    ~Not(){
        delete input;
        delete output;
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


    static int getInputSize(){
        return Not::inputSize;
    }

    static int getOutputSize(){
        return Not::outputSize;
    }
};

#endif