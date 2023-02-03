#ifndef INVERTER_8_BIT
#define INVERTER_8_BIT

#include<iostream>

#include "Component.h"

#include "InputArray.h"
#include "Not.h"
#include "Xor.h"

class Inverter8Bit : public Component {
    static const int inputSize = 8;
    static const int outputSize = 8;
    static const int invSize = 1;
    static int count;

    InputArray* input;
    InputArray* output;

    InputArray* inv;

    Xor* xo0;
    Xor* xo1;
    Xor* xo2;
    Xor* xo3;
    Xor* xo4;
    Xor* xo5;
    Xor* xo6;
    Xor* xo7;

    void propagate(){
        output->set(0, xo0->get());
        output->set(1, xo1->get());
        output->set(2, xo2->get());
        output->set(3, xo3->get());
        output->set(4, xo4->get());
        output->set(5, xo5->get());
        output->set(6, xo6->get());
        output->set(7, xo7->get());
    }

    void update(){
        xo0->set(0, input->get(0));
        xo0->set(1, inv->get(0));

        xo1->set(0, input->get(1));
        xo1->set(1, inv->get(0));

        xo2->set(0, input->get(2));
        xo2->set(1, inv->get(0));

        xo3->set(0, input->get(3));
        xo3->set(1, inv->get(0));

        xo4->set(0, input->get(4));
        xo4->set(1, inv->get(0));

        xo5->set(0, input->get(5));
        xo5->set(1, inv->get(0));

        xo6->set(0, input->get(6));
        xo6->set(1, inv->get(0));

        xo7->set(0, input->get(7));
        xo7->set(1, inv->get(0));
    }

    public:
    Inverter8Bit(){
        input = new InputArray(inputSize);
        output = new InputArray(outputSize);

        inv = new InputArray(invSize);

        xo0 = new Xor();
        xo1 = new Xor();
        xo2 = new Xor();
        xo3 = new Xor();
        xo4 = new Xor();
        xo5 = new Xor();
        xo6 = new Xor();
        xo7 = new Xor();

        update();
        propagate();

        Inverter8Bit::count ++;
    }

    Inverter8Bit(bool inputValue[]){
        input = new InputArray(inputValue, inputSize);
        output = new InputArray(outputSize);

        inv = new InputArray(invSize);

        xo0 = new Xor();
        xo1 = new Xor();
        xo2 = new Xor();
        xo3 = new Xor();
        xo4 = new Xor();
        xo5 = new Xor();
        xo6 = new Xor();
        xo7 = new Xor();

        update();
        propagate();

        Inverter8Bit::count ++;
    }

    ~Inverter8Bit(){
        delete input;
        delete output;

        delete inv;

        delete xo0;
        delete xo1;
        delete xo2;
        delete xo3;
        delete xo4;
        delete xo5;
        delete xo6;
        delete xo7;

        Inverter8Bit::count --;
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

    void setInv(bool value){
        inv->set(0, value);
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
        return Inverter8Bit::count;
    }

    static int getInputSize(){
        return Inverter8Bit::inputSize;
    }

    static int getOutputSize(){
        return Inverter8Bit::outputSize;
    }
};

int Inverter8Bit::count = 0;

#endif