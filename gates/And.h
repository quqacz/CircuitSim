#ifndef AND_GATE
#define AND_GATE

#include "InputArrayUtility.h"

// gate implements ( AB )

class And{
    static const int inputSize = 2;
    static const int outputSize = 1;
    static int count;

    InputArrayUtility* input;
    InputArrayUtility* output;

    void propagate(){
        output->set(0, input->get(0) && input->get(1));
    }

    public:

    And(){
        input = new InputArrayUtility(inputSize);
        output = new InputArrayUtility(outputSize);
        propagate();

        And::count ++;
    }

    And(bool inputValue[]){
        input = new InputArrayUtility(inputValue, inputSize);
        output = new InputArrayUtility(outputSize);
        propagate();

        And::count ++;
    }

    ~And(){
        delete input;
        delete output;

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
};

int And::count = 0;

#endif