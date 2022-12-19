#ifndef INPUT_H
#define INPUT_H

#include "Connector.h";
#include "Component.h";

class Input : Component
{
private:
    Connector* next = nullptr;
    bool state = 0;
public:
    Input(/* args */);
    Input(Connector*);
    ~Input();
    bool getState();
    void toggleState();
    void plug(Connector*);

};
#endif