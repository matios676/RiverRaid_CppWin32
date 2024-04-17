
#include "Canvas.h"
#include <cmath>
#define PI 3.14159265

#include <iostream>

#ifndef MAP_H
#define MAP_H


class Map : public Canvas {
    private:
        int RiverWidth;
        int centre;
        int currRiverPos;


    public:
        Map(int x, int y);

        ~Map();

        void MapDown();

        int cycle();

        void Update();
        int GetRiverPos();


private:
    Map(const Map& mp);
    Map& operator=(const Map& mp);


};

#endif
