#ifndef MUX_2_X_1
#define MUX_2_X_1

#include<iostream>
#include "TwoInputComponent.h"
#include "InputArray.h"
#include "Not.h"
#include "And.h"
#include "Or.h"

class Mux2X1 : TwoInputComponent {
    static const int inputSize = 1;
    static const int outputSize = 1;
    static const int sSize = 1;
    static int count;
    static const int truthTableSize = 8;
    static constexpr bool truthTable[truthTableSize] = {
        0, 0, 1, 1, 0, 1, 0, 1
    };

    InputArray* inputA;
    InputArray* inputB;

    InputArray* s;

    InputArray* output;

    Not* notS;

    And* inputA_notS;
    And* inputB_s;

    Or* inputA_notS__inputB_s;

    void update(){
        notS->set(s->get(0));

        inputA_notS->set(0, inputA->get(0));
        inputA_notS->set(1, notS->get());

        inputB_s->set(0, s->get(0));
        inputB_s->set(1, inputB->get(0));

        inputA_notS__inputB_s->set(0, inputA_notS->get());
        inputA_notS__inputB_s->set(1, inputB_s->get());
    }

    void propagate(){
        output->set(0, inputA_notS__inputB_s->get());
    }

public:
    Mux2X1(){
        inputA = new InputArray(inputSize);
        inputB = new InputArray(inputSize);

        s = new InputArray(sSize);

        output = new InputArray(outputSize);

        notS = new Not();

        inputA_notS = new And();
        inputB_s = new And();

        inputA_notS__inputB_s = new Or();

        update();
        propagate();

        Mux2X1::count ++;
    }
    ~Mux2X1(){
        delete inputA;
        delete inputB;
        delete s;
        delete output;
        delete notS;
        delete inputA_notS;
        delete inputB_s;
        delete inputA_notS__inputB_s;
    }

    bool* get(){
        return output->getValues();
    }

    bool get(int index){
        if(index < 0 || index > outputSize){
            throw std::invalid_argument("Requested invalid index");
        }
        return output->get(index);
    }

    void setA(int index, bool value){
        if(index < 0 || index > inputSize){
            throw std::invalid_argument("Requested invalid index");
        }
        inputA->set(index, value);
        update();
        propagate();
    }

    void setB(int index, bool value){
        if(index < 0 || index > inputSize){
            throw std::invalid_argument("Requested invalid index");
        }
        inputB->set(index, value);
        update();
        propagate();
    }

    void setA(bool values[]){
        inputA->set(values);
        update();
        propagate();
    }

    void setB(bool values[]){
        inputB->set(values);
        update();
        propagate();
    }

    void setS(bool value){
        s->set(0, value);
        update();
        propagate();
    }

    std::string toString(){
        return output->toString();
    }

    static int getCount(){
        return Mux2X1::count;
    }

    static int getInputSize(){
        return Mux2X1::inputSize;
    }

    static int getOutputSize(){
        return Mux2X1::outputSize;
    }

    static bool getTruthTableOutput(int index){
        if(index < 0 || index > Mux2X1::truthTableSize){
            throw std::invalid_argument("Requested invalid index");
        }
        return Mux2X1::truthTable[index];
    }

};

int Mux2X1::count = 0;

constexpr bool Mux2X1::truthTable[Mux2X1::truthTableSize];

#endif