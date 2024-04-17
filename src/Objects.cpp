
#include "../include/Objects.h"


Objects::Objects(int rows, int cols) : Canvas(rows, cols){
    fill(0);
};

Objects::~Objects(){
    if(_entities.size() > 0) for(int i=0;i<_entities.size();i++) delete _entities[i];
};

void Objects::SpawnEntity(int type, int hp, int x, int y){

    Entity* obj=0;
    switch(type){
        case SHIP: obj=new Ship(hp, x, y); break;
        case PLAYER: obj=new Jet(hp, x, y); break;
        //case AA: obj=new AA(hp, x, y); break;
        //case BOSS: obj=new BOSS(hp, x, y); break;
        default: obj=0;

    }

    _entities.push_back(obj);
    //delete obj; XXXXXXXXXXXX

}

void Objects::DrawEntities(){
    fill(0);
    for(int i=0;i<_entities.size();i++){
        if( _entities[i] != nullptr && _entities[i]->isAlive() ){
                for(int p=0;p<_entities[i]->GetSize();p++) //Y
                    for(int q=0;q<_entities[i]->GetSize();q++) //X
                        Set(_entities[i]->GetX()+q,_entities[i]->GetY()+p,_entities[i]->GetPart(q,p));
        }

    }
}

void Objects::KillEntity(int i){
    _entities[i]->Destroy(); //ustawia alive na 0
     delete _entities[i];
     _entities.erase(_entities.begin() + i);
}

void Objects::MoveDown(){
    for(int i=0;i<_entities.size();i++)
    if(_entities[i] != nullptr && _entities[i]->isAlive()){
        //_entities[i]->SetPos(_entities[i]->GetX(),_entities[i]->GetY()+1);
        Move(i,0, 1);
    }
}

void Objects::Move(int i,int x, int y){
    _entities[i]->SetPos(_entities[i]->GetX()+x,_entities[i]->GetY()+y);

}


void Objects::Update(){

    MoveDown();

    //if(_entities[0]->GetType() == 0)
        _entities[0]->SetPos(_entities[0]->GetX(), _entities[0]->GetY()-1); //player speed

    //jesli inne splynely poza mape - usun je
    for(int i=0;i<_entities.size();i++){
        if(_entities[i] != nullptr && _entities[i]->isAlive() && (_entities[i]->GetY()+_entities[i]->GetSize() > getHeight() || _entities[i]->GetY() < 0)){ //jesli obiektow nie bedzie mozna juz narysowac
            KillEntity(i);
        }
    }

    DrawEntities();

}

