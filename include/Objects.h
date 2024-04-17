
#include "Canvas.h"

//#include "Entity.h"
#include "Ship.h"
#include "Jet.h"
//#include "Bullet.h"

#include <vector>

//#ifndef EVENTS_H
    //#include "Events.h"
//#endif // EVENTS_H

#ifndef OBJECTS_H
#define OBJECTS_H

enum entity{
    PLAYER = 0,
    SHIP = 1,
    AA = 2,
    BOSS = 3

};


class Objects : public Canvas{
private:
    std::vector<Entity*> _entities;


public:
    Objects(int rows, int cols);

    ~Objects();

    void SpawnEntity(int type, int hp, int x, int y);
    void KillEntity(int i);
    void Update();

    void Move(int i, int x, int y);

    void MoveDown();
    void DrawEntities();

    friend class Events;

private:
    Objects(const Objects& Obj);
    Objects& operator=(const Objects& Obj);


};

#endif
