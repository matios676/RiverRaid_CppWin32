
#include "../include/Canvas.h"

Canvas::Canvas(int x, int y){
    _rows = y < 1 ? 1 : y; //zamiana
    _cols = x < 1 ? 1 : x;
    Create();
};

Canvas::~Canvas(){
    if(_Tab){
        for(int i=0; i< _rows; i++){
            delete[] _Tab[i];
        }
        delete[] _Tab;
    }
};

int Canvas::getHeight(){
    return _rows;
}

int Canvas::getWidth(){
    return _cols;
}


void Canvas::Create(){
    _Tab = new int*[_rows];
    for(int i=0;i<_rows;i++)
        _Tab[i] = new int[_cols];

};

void Canvas::fill(int value){
    for(int i=0;i<_rows;i++){
        for(int j=0;j<_cols;j++)
            _Tab[i][j] = value;
    }
}

void Canvas::SetX(int x, int value){
    for(int i=0;i<_rows;i++){_Tab[i][x] = value;}
};
            /*
           0**************x - cols
            *     |  #   *
            *     |  #   *
            *     |  #   *
            *-----+--#---*
            *     |  #   *
            *     |  #   *
    rows - y**************
            */


void Canvas::SetY(int y, int value){
    for(int i=0;i<_cols;i++){_Tab[y][i] = value;}
};

        /*
       0**************x
        *     |      *
        *############*
        *     |      *
        *-----+------*
        *     |      *
        *     |      *
       y**************
        */

int Canvas::Get(int x, int y){
    return _Tab[y][x];
}
void Canvas::Set(int x, int y, int value){
    _Tab[y][x]=value;
}

