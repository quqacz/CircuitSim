#ifndef XOR_8_BIT
#define XOR_8_BIT

#include<iostream>

#include "TwoInputComponent.h"

#include "InputArray.h"
#include "Xor.h"

class Xor8Bit : public TwoInputComponent {
    static const int inputSize = 8;
    static const int outputSize = 8;
    static const int invSize = 1;
    static int count;

    InputArray* inputA;
    InputArray* inputB;

    InputArray* output;

    Xor* xor0;
    Xor* xor1;
    Xor* xor2;
    Xor* xor3;
    Xor* xor4;
    Xor* xor5;
    Xor* xor6;
    Xor* xor7;

    void propagate(){
        output->set(0, xor0->get());
        output->set(1, xor1->get());
        output->set(2, xor2->get());
        output->set(3, xor3->get());
        output->set(4, xor4->get());
        output->set(5, xor5->get());
        output->set(6, xor6->get());
        output->set(7, xor7->get());
    }

    void update(){
        xor0->set(0, inputA->get(0));
        xor0->set(1, inputB->get(0));

        xor1->set(0, inputA->get(1));
        xor1->set(1, inputB->get(1));

        xor2->set(0, inputA->get(2));
        xor2->set(1, inputB->get(2));

        xor3->set(0, inputA->get(3));
        xor3->set(1, inputB->get(3));

        xor4->set(0, inputA->get(4));
        xor4->set(1, inputB->get(4));

        xor5->set(0, inputA->get(5));
        xor5->set(1, inputB->get(5));

        xor6->set(0, inputA->get(6));
        xor6->set(1, inputB->get(6));

        xor7->set(0, inputA->get(7));
        xor7->set(1, inputB->get(7));
    }

    public:
    Xor8Bit(){
        inputA = new InputArray(inputSize);
        inputB = new InputArray(inputSize);

        output = new InputArray(outputSize);

        xor0 = new Xor();
        xor1 = new Xor();
        xor2 = new Xor();
        xor3 = new Xor();
        xor4 = new Xor();
        xor5 = new Xor();
        xor6 = new Xor();
        xor7 = new Xor();

        update();
        propagate();

        Xor8Bit::count ++;
    }

    Xor8Bit(bool inputValueA[], bool inputValueB[]){
        inputA = new InputArray(inputValueA, inputSize);
        inputB = new InputArray(inputValueA, inputSize);

        output = new InputArray(outputSize);

        xor0 = new Xor();
        xor1 = new Xor();
        xor2 = new Xor();
        xor3 = new Xor();
        xor4 = new Xor();
        xor5 = new Xor();
        xor6 = new Xor();
        xor7 = new Xor();

        update();
        propagate();

        Xor8Bit::count ++;
    }

    ~Xor8Bit(){
        delete inputA;
        delete inputB;

        delete output;

        delete xor0;
        delete xor1;
        delete xor2;
        delete xor3;
        delete xor4;
        delete xor5;
        delete xor6;
        delete xor7;

        Xor8Bit::count --;
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
        return Xor8Bit::count;
    }

    static int getInputSize(){
        return Xor8Bit::inputSize;
    }

    static int getOutputSize(){
        return Xor8Bit::outputSize;
    }
};

int Xor8Bit::count = 0;

#endif