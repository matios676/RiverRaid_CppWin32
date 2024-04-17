
#include "../include/Input.h"



Input::Input(){
    for(int i=0;i<5;i++)
        keys[i]=0;
};
Input::~Input(){


};

bool* Input::getKeys(){
    return keys;
    };

void  Input::setKey(int index, bool state){
    keys[index]=state;
    };



