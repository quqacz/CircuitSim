#include "Input.h"

Input::Input()
{
}

Input::Input(Connector* next)
{
    this->next = next;
}

Input::~Input()
{
    this->next->unplug(this);
    this->next = nullptr;
}

bool Input::getState()
{
    return this->state;
}

void Input::toggleState()
{
    this->state = !this->state;
}

void Input::plug(Connector *next)
{
    this->next = next;
    this->next->setState(this->state);
}
