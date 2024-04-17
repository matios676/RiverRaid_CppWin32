#include "../include/Jet.h"

const int JETTYPE = 0;
const int JETSIZE = 4;
const int JETICON[4][4] =  {{0,0,3,0}, //  *
                            {0,0,3,0}, //  *
                            {0,3,3,3}, // ***
                            {0,3,0,3}}; //* *

Jet::Jet(int hp, int x, int y): Entity(hp, x, y, JETSIZE , JETTYPE){

};
Jet::~Jet(){

};

void Jet::attack(){

};
void Jet::weapon(){

};

int Jet::GetPart(int x, int y){
    return JETICON[y][x];
}

