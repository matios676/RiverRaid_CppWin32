
#include "Canvas.h"

#include "Map.h"
#include "Objects.h"

#include <cstdlib>
#include <time.h>

#include "Input.h"

#ifndef EVENTS_H
#define EVENTS_H

/*enum entity{
    PLAYER = 0,
    SHIP = 1,
    AA = 2,
    BOSS = 3

};*/


class Events : public Canvas {
    private:
        Map* _map;
        Objects* _obj;

        int _End;
        //1 - win
        //2 - lose

    public:
        Events(int x, int y);
        ~Events();

        void Player1();

        void Update();
        int isEnd();

        void PlayerMove(bool* keys);

        void CheckCollisions(int i);

        void concat();

private:
    Events(const Events& ev);
    Events& operator=(const Events& ev);


};

#endif
