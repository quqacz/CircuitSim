#ifndef AND_8_BIT
#define AND_8_BIT

#include<iostream>

#include "TwoInputComponent.h"

#include "InputArray.h"
#include "And.h"

class And8Bit : public TwoInputComponent {
    static const int inputSize = 8;
    static const int outputSize = 8;
    static int count;

    InputArray* inputA;
    InputArray* inputB;

    InputArray* output;

    And* and0;
    And* and1;
    And* and2;
    And* and3;
    And* and4;
    And* and5;
    And* and6;
    And* and7;

    void propagate(){
        output->set(0, and0->get());
        output->set(1, and1->get());
        output->set(2, and2->get());
        output->set(3, and3->get());
        output->set(4, and4->get());
        output->set(5, and5->get());
        output->set(6, and6->get());
        output->set(7, and7->get());
    }

    void update(){
        and0->set(0, inputA->get(0));
        and0->set(1, inputB->get(0));

        and1->set(0, inputA->get(1));
        and1->set(1, inputB->get(1));

        and2->set(0, inputA->get(2));
        and2->set(1, inputB->get(2));

        and3->set(0, inputA->get(3));
        and3->set(1, inputB->get(3));

        and4->set(0, inputA->get(4));
        and4->set(1, inputB->get(4));

        and5->set(0, inputA->get(5));
        and5->set(1, inputB->get(5));

        and6->set(0, inputA->get(6));
        and6->set(1, inputB->get(6));

        and7->set(0, inputA->get(7));
        and7->set(1, inputB->get(7));
    }

    public:
    And8Bit(){
        inputA = new InputArray(inputSize);
        inputB = new InputArray(inputSize);

        output = new InputArray(outputSize);

        and0 = new And();
        and1 = new And();
        and2 = new And();
        and3 = new And();
        and4 = new And();
        and5 = new And();
        and6 = new And();
        and7 = new And();

        update();
        propagate();

        And8Bit::count ++;
    }

    And8Bit(bool inputValueA[], bool inputValueB[]){
        inputA = new InputArray(inputValueA, inputSize);
        inputB = new InputArray(inputValueA, inputSize);

        output = new InputArray(outputSize);

        and0 = new And();
        and1 = new And();
        and2 = new And();
        and3 = new And();
        and4 = new And();
        and5 = new And();
        and6 = new And();
        and7 = new And();

        update();
        propagate();

        And8Bit::count ++;
    }

    ~And8Bit(){
        delete inputA;
        delete inputB;

        delete output;

        delete and0;
        delete and1;
        delete and2;
        delete and3;
        delete and4;
        delete and5;
        delete and6;
        delete and7;

        And8Bit::count --;
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
        return And8Bit::count;
    }

    static int getInputSize(){
        return And8Bit::inputSize;
    }

    static int getOutputSize(){
        return And8Bit::outputSize;
    }
};

int And8Bit::count = 0;

#endif