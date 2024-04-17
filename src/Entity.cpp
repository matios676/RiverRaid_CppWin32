#include "../include/Entity.h"

Entity::Entity(int hp, int x, int y, int Size, int type) : _Health(hp), _x(x),_y(y), _Size(Size), _Type(type){
    Alive=1;
    _Type=-1;
};

Entity::~Entity(){


};

int Entity::GetType(){
    return _Type;
    }
bool Entity::isAlive(){
    return Alive;
    }
void Entity::Destroy(){
    Alive = 0;
    }

int Entity::GetSize(){
    return _Size;
    }
int Entity::GetX(){
    return _x;
}
int Entity::GetY(){
    return _y;
}
void Entity::SetPos(int x, int y){
    _x=x;
    _y=y;
};

int Entity::GetHP(){
    return _Health;
}

