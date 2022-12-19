#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "Component.h"

class Connector
{
private:
    bool state = 0;
    Component* prev = nullptr;
    Component* next = nullptr;
public:
    Connector();
    Connector(Component*, Component*);
    Connector(Component*);
    ~Connector();
    bool getState();
    void setState(bool state);
    void setPrev(Component*);
    void setNext(Component*);
    void unplug(Component*);
};

#endif