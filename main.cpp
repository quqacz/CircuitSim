#include <iostream>

#include "InputArrayUtility.h"

using namespace std;

int main() {
    bool inputArray[8] = {1,1,1,1,0,0,0,0};
    unsigned short length = 8;
    InputArrayUtility* input = new InputArrayUtility(inputArray, length);
    
    // // expected output 1, 1, 1, 1, 0, 0, 0, 0,
    // for(int i = 0; i < length; i++){
    //     cout << input->get(i) << ", ";
    // }
    // cout << endl;

    // // expected output 1
    // cout << input->get(0) << endl;

    // // expected output 0
    // input->set(0, false);
    // cout << input->get(0) << endl;

    // // expected output 1, 0, 0, 0, 1, 1, 1, 1,
    // input->setNot();
    // for(int i = 0; i < length; i++){
    //     cout << input->get(i) << ", ";
    // }
    // cout << endl;

    cout<<input->toString()<<endl;

    delete input;
	return 0;
}