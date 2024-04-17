
#include "../include/Map.h"


Map::Map(int x, int y) : Canvas(x, y){
    fill(0);
    RiverWidth = 15;
    centre = x/2;
    currRiverPos = centre;

};

Map::~Map(){

};

void Map::MapDown(){
    for(int i=getHeight()-1;i>0;i--){
        for(int j=0;j<getWidth();j++)
            Set(j,i,Get(j,i-1));
    }
}

int Map::cycle(){
    static double sin_cycle=0;
    if(sin_cycle < 2*PI)
        sin_cycle += PI/20; //(jak szybko ma skrecac)
    else
        sin_cycle = PI/20;

    return 20*sin(sin_cycle); //(jak szeroko ma skrecac)*sin
}

void Map::Update(){
    MapDown();

    currRiverPos = centre+cycle();

    for(int i=0;i<getWidth();i++){
        if(i > (currRiverPos)-RiverWidth && i < (currRiverPos)+RiverWidth)
            Set(i,0, 0);
        else
            Set(i,0, 1);
    }

}

int Map::GetRiverPos(){
    return currRiverPos;
    }
