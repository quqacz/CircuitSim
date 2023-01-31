#ifndef NAND_GATE
#define NAND_GATE

#include "InputArray.h"
#include "Gate.h"
#include "Not.h"
#include "And.h"

// gate implements !(AB)

class Nand : public Gate {
    static const int inputSize = 2;
    static const int outputSize = 1;
    static int count;

    static const int truthTableRows = 4;
    static const int truthTableInputCollumns = 2;

    static constexpr bool truthTableInput[truthTableRows][truthTableInputCollumns]= {
        {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };

    static constexpr bool truthTableOutput[truthTableRows] = {
        1, 1, 1, 0
    };

    InputArray* input;
    InputArray* output;

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
        input = new InputArray(inputSize);
        output = new InputArray(outputSize);

        n_AB = new Not();
        AB = new And();

        update();
        propagate();

        Nand::count ++;
    }

    Nand(bool inputValue[]){
        input = new InputArray(inputValue, inputSize);
        output = new InputArray(outputSize);

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

    static int getTruthTableRowsCount(){
        return Nand::truthTableRows;
    }

    static bool* getTruthTableInput(int index){
        if(index < 0 || index > Nand::truthTableRows){
            throw std::invalid_argument("Requested invalid index");
        }

        bool* entry = new bool(Nand::truthTableInputCollumns);
        for(int i = 0; i < Nand::truthTableInputCollumns; i++){
            entry[i] = Nand::truthTableInput[index][i];
        }

        return entry;
    }

    static bool getTruthTableOutput(int index){
        if(index < 0 || index > Nand::truthTableRows){
            throw std::invalid_argument("Requested invalid index");
        }
        return Nand::truthTableOutput[index];
    }

    static void printTruthTable(){
        for(int i = 0; i < Nand::truthTableRows; i++){
            for(int j = 0; j < Nand::truthTableInputCollumns; j++){
                std::cout<< Nand::truthTableInput[i][j] << " ";
            }
            std::cout<< "|" << Nand::truthTableOutput[i] << std::endl; 
        }
    }
};

int Nand::count = 0;

constexpr bool Nand::truthTableInput[Nand::truthTableRows][Nand::truthTableInputCollumns];
constexpr bool Nand::truthTableOutput[Nand::truthTableRows];

#endif