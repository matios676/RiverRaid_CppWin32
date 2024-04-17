#include "../include/Keyboard.h"

Keyboard::Keyboard(){

};
Keyboard::~Keyboard(){

};

void Keyboard::translateKeys(){
    if(GetAsyncKeyState(VK_UP) < 0)
        setKey(GORA, true);
    else
        setKey(GORA, false);
    if(GetAsyncKeyState(VK_LEFT) < 0)
        setKey(LEWO, true);
    else
        setKey(LEWO, false);
    if(GetAsyncKeyState(VK_RIGHT) < 0)
        setKey(PRAWO, true);
    else
        setKey(PRAWO, false);
    if(GetAsyncKeyState(VK_DOWN) < 0)
        setKey(DOL, true);
    else
        setKey(DOL, false);

};

