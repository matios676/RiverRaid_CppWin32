#include "../include/Events.h"


Events::Events(int x, int y) : Canvas(x, y){
    fill(0);

    _End = 0;

    _map = new Map(x,y);
    _obj = new Objects(x, y);

};

Events::~Events(){
    if(_map) delete _map;
    if(_obj) delete _obj;
};

void Events::Player1(){
    if(_obj != nullptr && _map != nullptr)
        _obj->SpawnEntity(PLAYER,1,_map->GetRiverPos(),_map->getHeight()-10);
}

int Events::isEnd(){
    return _End;
    }


void Events::Update(){
    static int t=0;

    if(t == 0){
        t = (rand()%10)+6;
        _obj->SpawnEntity(SHIP,3,_map->GetRiverPos(),1);
    }
    t--;

    _map->Update();
    _obj->Update();

    if(_obj->_entities[0]->GetY() <= 0)
        _End = 1;
    else if(_obj->_entities[0]->GetY()+_obj->_entities[0]->GetSize() >= getHeight())
        _End = 2;

    concat();

    CheckCollisions(0); //moze tutaj

}

void Events::PlayerMove(bool* keys){
    if(keys[GORA]) //Up
        _obj->Move(0, 0,-1);
    if(keys[LEWO]) //Left
        _obj->Move(0,-1, 0);
    if(keys[PRAWO]) //Right
        _obj->Move(0, 1, 0);
    if(keys[DOL]) //Down
        _obj->Move(0, 0, 1);

}

void Events::concat(){
    for(int i=0;i<getHeight();i++) //Y
        for(int j=0;j<getWidth();j++) //X
            if( j<_map->getWidth() && i<_map->getHeight() ){
                    Set( j, i, _map->Get(j, i) ); //mapa
                    if( _obj->Get(j, i) != 0 )
                        Set( j, i, _obj->Get(j, i) ); //obiekty
            }
}

void Events::CheckCollisions(int i){
    int objects_collide=0;
    int map_collide=0;
    int obj_part=0;

        if( _obj->_entities[i] != nullptr && _obj->_entities[i]->isAlive() ){
              for(int p=0;p<_obj->_entities[i]->GetSize();p++) //Y
              for(int q=0;q<_obj->_entities[i]->GetSize();q++){ //X
                objects_collide = _obj->Get(_obj->_entities[i]->GetX()+q,_obj->_entities[i]->GetY()+p);
                map_collide = _map->Get(_obj->_entities[i]->GetX()+q,_obj->_entities[i]->GetY()+p);
                obj_part = _obj->_entities[i]->GetPart(q,p);
                if(  ((map_collide != obj_part && map_collide != 0) || (objects_collide != obj_part && objects_collide != 0))  && obj_part != 0 )

                    _End = 2;

              }
        }
}

