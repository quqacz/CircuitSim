#ifndef GATE_INTERFACE
#define GATE_INTERFACE

class Gate{
    public:
    virtual bool get() = 0;
    virtual void set(bool values[]) = 0;
    virtual void set(int index, bool value) = 0;
};

#endif