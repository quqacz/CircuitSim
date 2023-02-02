#ifndef CLEAR_8_BIT
#define CLEAR_8_BIT

#include<iostream>

#include "Component.h"

#include "InputArray.h"
#include "Not.h"
#include "And.h"

class Clear8Bit : public Component {
    static const int inputSize = 8;
    static const int outputSize = 8;
    static const int clrSize = 1;
    static int count;

    InputArray* input;
    InputArray* output;

    InputArray* clr;

    Not* notClr;

    And* a0;
    And* a1;
    And* a2;
    And* a3;
    And* a4;
    And* a5;
    And* a6;
    And* a7;

    void propagate(){
        output->set(0, a0->get());
        output->set(1, a1->get());
        output->set(2, a2->get());
        output->set(3, a3->get());
        output->set(4, a4->get());
        output->set(5, a5->get());
        output->set(6, a6->get());
        output->set(7, a7->get());
    }

    void update(){
        notClr->set(clr->get(0));

        a0->set(0, input->get(0));
        a0->set(1, notClr->get());

        a1->set(0, input->get(1));
        a1->set(1, notClr->get());

        a2->set(0, input->get(2));
        a2->set(1, notClr->get());

        a3->set(0, input->get(3));
        a3->set(1, notClr->get());

        a4->set(0, input->get(4));
        a4->set(1, notClr->get());

        a5->set(0, input->get(5));
        a5->set(1, notClr->get());

        a6->set(0, input->get(6));
        a6->set(1, notClr->get());

        a7->set(0, input->get(7));
        a7->set(1, notClr->get());
    }

    public:
    Clear8Bit(){
        input = new InputArray(inputSize);
        output = new InputArray(outputSize);

        clr = new InputArray(clrSize);

        notClr = new Not();

        a0 = new And();
        a1 = new And();
        a2 = new And();
        a3 = new And();
        a4 = new And();
        a5 = new And();
        a6 = new And();
        a7 = new And();

        update();
        propagate();

        Clear8Bit::count ++;
    }

    Clear8Bit(bool inputValue[]){
        input = new InputArray(inputValue, inputSize);
        output = new InputArray(outputSize);

        clr = new InputArray(clrSize);

        notClr = new Not();

        a0 = new And();
        a1 = new And();
        a2 = new And();
        a3 = new And();
        a4 = new And();
        a5 = new And();
        a6 = new And();
        a7 = new And();

        update();
        propagate();

        Clear8Bit::count ++;
    }

    ~Clear8Bit(){
        delete input;
        delete output;

        delete clr;

        delete notClr;

        delete a0;
        delete a1;
        delete a2;
        delete a3;
        delete a4;
        delete a5;
        delete a6;
        delete a7;

        Clear8Bit::count --;
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

    void setClr(bool value){
        clr->set(0, value);
        update();
        propagate();
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
        return Clear8Bit::count;
    }

    static int getInputSize(){
        return Clear8Bit::inputSize;
    }

    static int getOutputSize(){
        return Clear8Bit::outputSize;
    }
};

int Clear8Bit::count = 0;

#endif