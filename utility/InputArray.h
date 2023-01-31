#ifndef INPUT_ARRAY_UTILITY
#define INPUT_ARRAY_UTILITY

#include<iostream>
#include<string>

class InputArray
{
    bool* values;
    int length;

    public:
    
    InputArray(bool values[], int size) {
        this->length = size;
        this->values = new bool(this->length);
        for(auto i = 0; i < this->length; i++){
            this->values[i] = values[i]; 
        }
    }

    InputArray(int size){
        this->length = size;
        this->values = new bool(this->length);
        for(auto i = 0; i < this->length; i++){
            this->values[i] = 0; 
        }
    }

    ~InputArray(){
        delete [] values;
    }

    int size(){
        return this->length;
    }

    bool get(int index){
        if(index < 0 || index > this->length){
            throw std::invalid_argument("Requested invalid index");
        }
        return this->values[index];
    }

    bool* getValues(){
        bool* state = new bool(this->length);

        for(auto i = 0; i < this->length; i++){
            state[i] = this->values[i];
        }

        return state;
    }

    std::string toString(){
        std::string output = "";

        for(auto i = 0; i < this->length; i++){
            if(this->values[i]){
                output = output + "1";
            }else{
                output = output + "0";
            }
        }

        return output;
    }

    char* getChars(){
        char* state = new char(this->length);

        for(auto i = 0; i < this->length; i++){
            if(this->values[i]){
                state[i] = '1';
            }else{
                state[i] = '0';
            }
        }

        return state;
    }

    void set(int index, bool value){
        if(index < 0 || index > this->length){
            throw std::invalid_argument("Requested invalid index");
        }
        this->values[index] = value;
    }

    void set(bool values[]){
        for(auto i = 0; i < this->length; i++){
            this->values[i] = values[i]; 
        }
    }

    void setNot(){
        for(auto i = 0; i < this->length; i++){
            this->values[i] = !this->values[i]; 
        }
    }

    void setAnd(bool values[]){
        for(auto i = 0; i < this->length; i++){
            this->values[i] = values[i] && this->values[i]; 
        }
    }

    void setOr(bool values[]){
        for(auto i = 0; i < this->length; i++){
            this->values[i] = values[i] || this->values[i]; 
        }
    }

    void setXor(bool values[]){
        for(auto i = 0; i < this->length; i++){
            this->values[i] = values[i] ^ this->values[i]; 
        }
    }
};

#endif