#ifndef NOR_GATE
#define NOR_GATE

#include "InputArrayUtility.h"
#include "Not.h"
#include "Or.h"

// gate implements !(A + B)

class Nor{
    static const int inputSize = 2;
    static const int outputSize = 1;
    static int count;

    InputArrayUtility* input;
    InputArrayUtility* output;

    Not* n_AoB;
    Or* AoB;

    void update(){
        AoB->set(0, input->get(0));
        AoB->set(1, input->get(1));

        n_AoB->set(AoB->get());
    }

    void propagate(){
        output->set(0, n_AoB->get());
    }

    public:

    Nor(){
        input = new InputArrayUtility(inputSize);
        output = new InputArrayUtility(outputSize);

        n_AoB = new Not();
        AoB = new Or();
        update();
        propagate();
    }

    Nor(bool inputValue[]){
        input = new InputArrayUtility(inputValue, inputSize);
        output = new InputArrayUtility(outputSize);

        n_AoB = new Not();
        AoB = new Or();
        update();
        propagate();
    }

    ~Nor(){
        delete input;
        delete output;

        delete AoB;
        delete n_AoB;
    }

    bool get(){
        return output->get(0);
    }

    void set(int index, bool value){
        if(index < 0 || index > inputSize){
            throw std::invalid_argument("Requested invalid index");
        }
        input->set(index, value);

        update();
        propagate();
    }

    void set(bool values[]){
        input->set(values);
        
        update();
        propagate();
    }

    std::string toString(){
        return output->toString();
    }

    static int getInputSize(){
        return Nor::inputSize;
    }

    static int getOutputSize(){
        return Nor::outputSize;
    }
};

#endif