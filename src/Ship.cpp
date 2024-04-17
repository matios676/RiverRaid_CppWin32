#include "../include/Ship.h"

const int SHIPTYPE = 1;
const int SHIPSIZE = 6;
const int SHIPICON[6][6] = {{0,0,0,0,0,0}, //
                            {0,0,2,0,2,0}, //  * *
                            {2,0,2,0,2,2}, //* * **
                            {0,2,2,2,2,2}, // *****
                            {0,2,2,2,2,0}, // ****
                            {0,0,0,0,0,0}};//


Ship::Ship(int hp, int x, int y) : Entity(hp, x, y, SHIPSIZE, SHIPTYPE){

};
Ship::~Ship(){

};

void Ship::attack(){

};
void Ship::weapon(){

};

int Ship::GetPart(int x, int y){
    return SHIPICON[y][x];
};

