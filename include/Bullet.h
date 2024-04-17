#ifndef ENTITY_H
    #include "Entity.h"
#endif

#ifndef BULLET_H
#define BULLET_H

class Bullet : public Entity {

    public:
        Bullet(int hp, int x, int y);
        ~Bullet();

        virtual void attack();
        virtual void weapon();

        virtual int GetPart(int x, int y);

private:
    Bullet(const Bullet& Bu);
    Bullet& operator=(const Bullet& Bu);

};

#endif
