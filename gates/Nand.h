#ifndef NAND_GATE
#define NAND_GATE

#include "InputArrayUtility.h"
#include "Not.h"
#include "And.h"

// gate implements !(AB)

class Nand{
    static const int inputSize = 2;
    static const int outputSize = 1;
    static int count;

    InputArrayUtility* input;
    InputArrayUtility* output;

    Not* n_AB;
    And* AB;

    void update(){
        AB->set(0, input->get(0));
        AB->set(1, input->get(1));

        n_AB->set(AB->get());
    }

    void propagate(){
        output->set(0, n_AB->get());
    }

    public:

    Nand(){
        input = new InputArrayUtility(inputSize);
        output = new InputArrayUtility(outputSize);

        n_AB = new Not();
        AB = new And();

        update();
        propagate();

        Nand::count ++;
    }

    Nand(bool inputValue[]){
        input = new InputArrayUtility(inputValue, inputSize);
        output = new InputArrayUtility(outputSize);

        n_AB = new Not();
        AB = new And();

        update();
        propagate();

        Nand::count ++;
    }

    ~Nand(){
        delete input;
        delete output;

        delete AB;
        delete n_AB;

        Nand::count --;
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
        return Nand::count;
    }

    static int getInputSize(){
        return Nand::inputSize;
    }

    static int getOutputSize(){
        return Nand::outputSize;
    }
};

int Nand::count = 0;

#endif