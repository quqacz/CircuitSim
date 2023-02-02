#ifndef COMPONENT_INTERFACE
#define COMPONENT_INTERFACE

class Component{
    public:
    virtual bool* get() = 0;
    virtual bool get(int index) = 0;
    virtual void set(bool values[]) = 0;
    virtual void set(int index, bool value) = 0;
};

#endif