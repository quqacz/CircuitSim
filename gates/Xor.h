#ifndef XOR_GATE
#define XOR_GATE

#include "InputArrayUtility.h"
#include "Not.h"
#include "And.h"
#include "Or.h"

// gate implements ( A!B ) + ( !AB )

class Xor{
    static const int inputSize = 2;
    static const int outputSize = 1;
    static int count;

    InputArrayUtility* input;
    InputArrayUtility* output;

    Not* nB;
    Not* nA;

    And* AnB;
    And* nAB;

    Or* AnB_nAB;

    void update(){
        nA->set(input->get(0));
        nB->set(input->get(1));

        AnB->set(0, input->get(0));
        AnB->set(1, nB->get());

        nAB->set(0, nA->get());
        nAB->set(1, input->get(1));

        AnB_nAB->set(0, AnB->get());
        AnB_nAB->set(1, nAB->get());
    }

    void propagate(){
        output->set(0, AnB_nAB->get());
    }

    public:

    Xor(){
        input = new InputArrayUtility(inputSize);
        output = new InputArrayUtility(outputSize);

        nA = new Not();
        nB = new Not();
        
        AnB = new And();
        nAB = new And();

        AnB_nAB = new Or();

        update();
        propagate();

        Xor::count ++;
    }

    Xor(bool inputValue[]){
        input = new InputArrayUtility(inputValue, inputSize);
        output = new InputArrayUtility(outputSize);

        nA = new Not();
        nB = new Not();

        AnB = new And();
        nAB = new And();

        AnB_nAB = new Or();

        update();
        propagate();

        Xor::count ++;
    }

    ~Xor(){
        delete input;
        delete output;

        delete nA;
        delete nB;

        delete AnB;
        delete nAB;

        delete AnB_nAB;

        Xor::count --;
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

    static int getCount(){
        return Xor::count;
    }

    static int getInputSize(){
        return Xor::inputSize;
    }

    static int getOutputSize(){
        return Xor::outputSize;
    }
};

int Xor::count = 0;

#endif