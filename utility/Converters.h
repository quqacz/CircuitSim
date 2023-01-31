#ifndef CONVERTERS
#define CONVERTERS

bool* decymalToBinary(int number, int size)
{
    bool* result = new bool(size);

    for(auto i = 0; i < size; i++){
        result[i] = 0;
    }
 
    for (int i = size - 1; i >= 0; i--) {
        int k = number >> i;
        if (k & 1)
            result[i] = 1;
        else
            result[i] = 0;
    }
    
    for (auto i = 0, j = size - 1; i < size/2; i++, j--)  
    {     
        auto temp = result[i];  
        result[i] = result[j];  
        result[j] = temp;  
    }

    return result;
}

#endif