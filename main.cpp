#include<iostream>

#include "And.h"
#include "Input.h"
#include "Connector.h"

int main(){
    Input* i0 = new Input();
    Input* i1 = new Input();
    Connector* i0Connector = new Connector();
    Connector* i1Connector = new Connector();
    i0->plug(i0Connector);
    i1->plug(i1Connector);

    And* a0 = new And(i0Connector, i1Connector);
    std::cout<<a0->getO0();
    return 0;
}