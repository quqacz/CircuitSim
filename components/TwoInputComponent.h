#ifndef TWO_INPUT_COMPONENT_INTERFACE
#define TWO_INPUT_COMPONENT_INTERFACE

class TwoInputComponent{
    public:
    virtual bool* get() = 0;
    virtual bool get(int index) = 0;
    virtual void setA(bool values[]) = 0;
    virtual void setA(int index, bool value) = 0;
    virtual void setB(bool values[]) = 0;
    virtual void setB(int index, bool value) = 0;
};

#endif