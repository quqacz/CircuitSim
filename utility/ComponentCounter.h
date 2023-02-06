#ifndef COMPONENT_COUNTER
#define COMPONENT_COUNTER

#include<iostream>

#include "Not.h"
#include "And.h"
#include "Or.h"
#include "Xor.h"
#include "Nand.h"
#include "Nor.h"
#include "Xnor.h"
#include "Clear8Bit.h"
#include "Inverter8Bit.h"
#include "And8Bit.h"
#include "Or8Bit.h"
#include "Xor8Bit.h"
#include "Mux2X1.h"

class ComponentsCounter {
    int andGate = 0;
    int nandGate = 0;
    int norGate = 0;
    int notGate = 0;
    int orGate = 0;
    int xnorGate = 0;
    int xorGate = 0;

    int and8Bit = 0;
    int clear8Bit = 0;
    int inverter8Bit = 0;
    int mux2X1 = 0;
    int or8Bit = 0;
    int xor8Bit = 0;

    public:

    void addCount(){
        andGate += And::getCount();
        nandGate += Nand::getCount();
        norGate += Nor::getCount();
        notGate += Not::getCount();
        orGate += Or::getCount();
        xnorGate += Xnor::getCount();
        xorGate += Xor::getCount();

        and8Bit += And8Bit::getCount();
        clear8Bit += Clear8Bit::getCount();
        inverter8Bit += Inverter8Bit::getCount();
        mux2X1 += Mux2X1::getCount();
        or8Bit += Or8Bit::getCount();
        xor8Bit += Xor8Bit::getCount();
    }

    void print(){
        std::cout<<"And count: " << andGate << std::endl;
        std::cout<<"Nand count: " << nandGate << std::endl;
        std::cout<<"Nor count: " << norGate << std::endl;
        std::cout<<"Not count: " << notGate << std::endl;
        std::cout<<"Or count: " << orGate << std::endl;
        std::cout<<"Xnor count: " << xnorGate << std::endl;
        std::cout<<"Xor count: " << xorGate << std::endl;

        std::cout<<"And8Bit count: " << and8Bit << std::endl;
        std::cout<<"Clear8Bit count: " << clear8Bit << std::endl;
        std::cout<<"Inverter8Bit count: " << inverter8Bit << std::endl;
        std::cout<<"Mux2X1 count: " << mux2X1 << std::endl;
        std::cout<<"Or8Bit count: " << or8Bit << std::endl;
        std::cout<<"Xor8Bit count: " << xor8Bit << std::endl;

    }
};

#endif