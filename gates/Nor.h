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

    static const int truthTableRows = 4;
    static const int truthTableInputCollumns = 2;

    static constexpr bool truthTableInput[truthTableRows][truthTableInputCollumns]= {
        {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };

    static constexpr bool truthTableOutput[truthTableRows] = {
        1, 0, 0, 0
    };

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

        Nor::count ++;
    }

    Nor(bool inputValue[]){
        input = new InputArrayUtility(inputValue, inputSize);
        output = new InputArrayUtility(outputSize);

        n_AoB = new Not();
        AoB = new Or();

        update();
        propagate();

        Nor::count ++;
    }

    ~Nor(){
        delete input;
        delete output;

        delete AoB;
        delete n_AoB;

        Nor::count --;
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
        return Nor::count;
    }

    static int getInputSize(){
        return Nor::inputSize;
    }

    static int getOutputSize(){
        return Nor::outputSize;
    }

        static int getTruthTableRowsCount(){
        return Nor::truthTableRows;
    }

    static bool* getTruthTableInput(int index){
        if(index < 0 || index > Nor::truthTableRows){
            throw std::invalid_argument("Requested invalid index");
        }

        bool* entry = new bool(Nor::truthTableInputCollumns);
        for(int i = 0; i < Nor::truthTableInputCollumns; i++){
            entry[i] = Nor::truthTableInput[index][i];
        }

        return entry;
    }

    static bool getTruthTableOutput(int index){
        if(index < 0 || index > Nor::truthTableRows){
            throw std::invalid_argument("Requested invalid index");
        }
        return Nor::truthTableOutput[index];
    }

    static void printTruthTable(){
        for(int i = 0; i < Nor::truthTableRows; i++){
            for(int j = 0; j < Nor::truthTableInputCollumns; j++){
                std::cout<< Nor::truthTableInput[i][j] << " ";
            }
            std::cout<< "|" << Nor::truthTableOutput[i] << std::endl; 
        }
    }
};

int Nor::count = 0;

constexpr bool Nor::truthTableInput[Nor::truthTableRows][Nor::truthTableInputCollumns];
constexpr bool Nor::truthTableOutput[Nor::truthTableRows];

#endif