
#include "../include/Bullet.h"

const int BULLETTYPE = 7;
const int BULLETSIZE = 1;
const int BULLETICON[1][1] =  {{3}};

Bullet::Bullet(int hp, int x, int y): Entity(hp, x, y, BULLETSIZE , BULLETTYPE){


};
Bullet::~Bullet(){


};

void Bullet::attack(){

};
void Bullet::weapon(){


};

int Bullet::GetPart(int x, int y){
	return 0;
};

