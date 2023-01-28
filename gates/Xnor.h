#ifndef XNOR_GATE
#define XNOR_GATE

#include "InputArrayUtility.h"
#include "Nor.h"
#include "And.h"
#include "Or.h"

// gate implements ( AB ) + ( !A!B ) 

class Xnor{
    static const int inputSize = 2;
    static const int outputSize = 1;
    static int count;

    InputArrayUtility* input;
    InputArrayUtility* output;

    Nor* AnorB;

    And* AandB;

    Or* AnorB_AandB;

    void update(){
        AnorB->set(0, input->get(0));
        AnorB->set(1, input->get(1));

        AandB->set(0, input->get(0));
        AandB->set(1, input->get(1));

        AnorB_AandB->set(0, AnorB->get());
        AnorB_AandB->set(1, AandB->get());
    }

    void propagate(){
        output->set(0, AnorB_AandB->get());
    }

    public:

    Xnor(){
        input = new InputArrayUtility(inputSize);
        output = new InputArrayUtility(outputSize);

        AnorB = new Nor();

        AandB = new And();

        AnorB_AandB = new Or();

        update();
        propagate();
    }

    Xnor(bool inputValue[]){
        input = new InputArrayUtility(inputValue, inputSize);
        output = new InputArrayUtility(outputSize);

        AnorB = new Nor();

        AandB = new And();

        AnorB_AandB = new Or();

        update();
        propagate();
    }

    ~Xnor(){
        delete input;
        delete output;

        delete AnorB;

        delete AandB;

        delete AnorB_AandB;
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
        return Xnor::inputSize;
    }

    static int getOutputSize(){
        return Xnor::outputSize;
    }
};

#endif