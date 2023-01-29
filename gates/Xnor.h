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

    static const int truthTableRows = 4;
    static const int truthTableInputCollumns = 2;

    static constexpr bool truthTableInput[truthTableRows][truthTableInputCollumns]= {
        {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };

    static constexpr bool truthTableOutput[truthTableRows] = {
        1, 0, 0, 1
    };

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

        Xnor::count ++;
    }

    Xnor(bool inputValue[]){
        input = new InputArrayUtility(inputValue, inputSize);
        output = new InputArrayUtility(outputSize);

        AnorB = new Nor();

        AandB = new And();

        AnorB_AandB = new Or();

        update();
        propagate();

        Xnor::count ++;
    }

    ~Xnor(){
        delete input;
        delete output;

        delete AnorB;

        delete AandB;

        delete AnorB_AandB;

        Xnor::count --;
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
        return Xnor::count;
    }

    static int getInputSize(){
        return Xnor::inputSize;
    }

    static int getOutputSize(){
        return Xnor::outputSize;
    }

        static int getTruthTableRowsCount(){
        return Xnor::truthTableRows;
    }

    static bool* getTruthTableInput(int index){
        if(index < 0 || index > Xnor::truthTableRows){
            throw std::invalid_argument("Requested invalid index");
        }

        bool* entry = new bool(Xnor::truthTableInputCollumns);
        for(int i = 0; i < Xnor::truthTableInputCollumns; i++){
            entry[i] = Xnor::truthTableInput[index][i];
        }

        return entry;
    }

    static bool getTruthTableOutput(int index){
        if(index < 0 || index > Xnor::truthTableRows){
            throw std::invalid_argument("Requested invalid index");
        }
        return Xnor::truthTableOutput[index];
    }

    static void printTruthTable(){
        for(int i = 0; i < Xnor::truthTableRows; i++){
            for(int j = 0; j < Xnor::truthTableInputCollumns; j++){
                std::cout<< Xnor::truthTableInput[i][j] << " ";
            }
            std::cout<< "|" << Xnor::truthTableOutput[i] << std::endl; 
        }
    }
};

int Xnor::count = 0;

constexpr bool Xnor::truthTableInput[Xnor::truthTableRows][Xnor::truthTableInputCollumns];
constexpr bool Xnor::truthTableOutput[Xnor::truthTableRows];

#endif