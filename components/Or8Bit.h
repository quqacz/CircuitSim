#ifndef OR_8_BIT
#define OR_8_BIT

#include<iostream>

#include "TwoInputComponent.h"

#include "InputArray.h"
#include "Or.h"

class Or8Bit : public TwoInputComponent {
    static const int inputSize = 8;
    static const int outputSize = 8;
    static int count;

    InputArray* inputA;
    InputArray* inputB;

    InputArray* output;

    Or* or0;
    Or* or1;
    Or* or2;
    Or* or3;
    Or* or4;
    Or* or5;
    Or* or6;
    Or* or7;

    void propagate(){
        output->set(0, or0->get());
        output->set(1, or1->get());
        output->set(2, or2->get());
        output->set(3, or3->get());
        output->set(4, or4->get());
        output->set(5, or5->get());
        output->set(6, or6->get());
        output->set(7, or7->get());
    }

    void update(){
        or0->set(0, inputA->get(0));
        or0->set(1, inputB->get(0));

        or1->set(0, inputA->get(1));
        or1->set(1, inputB->get(1));

        or2->set(0, inputA->get(2));
        or2->set(1, inputB->get(2));

        or3->set(0, inputA->get(3));
        or3->set(1, inputB->get(3));

        or4->set(0, inputA->get(4));
        or4->set(1, inputB->get(4));

        or5->set(0, inputA->get(5));
        or5->set(1, inputB->get(5));

        or6->set(0, inputA->get(6));
        or6->set(1, inputB->get(6));

        or7->set(0, inputA->get(7));
        or7->set(1, inputB->get(7));
    }

    public:
    Or8Bit(){
        inputA = new InputArray(inputSize);
        inputB = new InputArray(inputSize);

        output = new InputArray(outputSize);

        or0 = new Or();
        or1 = new Or();
        or2 = new Or();
        or3 = new Or();
        or4 = new Or();
        or5 = new Or();
        or6 = new Or();
        or7 = new Or();

        update();
        propagate();

        Or8Bit::count ++;
    }

    Or8Bit(bool inputValueA[], bool inputValueB[]){
        inputA = new InputArray(inputValueA, inputSize);
        inputB = new InputArray(inputValueA, inputSize);

        output = new InputArray(outputSize);

        or0 = new Or();
        or1 = new Or();
        or2 = new Or();
        or3 = new Or();
        or4 = new Or();
        or5 = new Or();
        or6 = new Or();
        or7 = new Or();

        update();
        propagate();

        Or8Bit::count ++;
    }

    ~Or8Bit(){
        delete inputA;
        delete inputB;

        delete output;

        delete or0;
        delete or1;
        delete or2;
        delete or3;
        delete or4;
        delete or5;
        delete or6;
        delete or7;

        Or8Bit::count --;
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
        inputA->set(index, value);
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

    std::string toString(){
        return output->toString();
    }

    static int getCount(){
        return Or8Bit::count;
    }

    static int getInputSize(){
        return Or8Bit::inputSize;
    }

    static int getOutputSize(){
        return Or8Bit::outputSize;
    }
};

int Or8Bit::count = 0;

#endif