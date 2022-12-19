#include "Connector.h"

Connector::Connector()
{
}

Connector::Connector(Component* prev, Component* next)
{
    this->setPrev(prev);
    this->setNext(next);
}

Connector::Connector(Component* prev)
{
    this->setPrev(prev);
}

Connector::~Connector()
{
    this->prev = nullptr;
    this->next = nullptr;
}

bool Connector::getState()
{
    return this->state;
}

void Connector::setState(bool state)
{
    this -> state = state;
}

void Connector::setPrev(Component* prev)
{
    this->prev = prev;
}

void Connector::setNext(Component* next)
{
    this->next = next;
}

void Connector::unplug(Component* component)
{
    if(prev == component)
        prev = nullptr;

    if(next == component)
        next = nullptr;

    if(next == nullptr && prev == nullptr)
        this->~Connector();
}
