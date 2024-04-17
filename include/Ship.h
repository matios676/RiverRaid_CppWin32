#ifndef ENTITY_H
    #include "Entity.h"
#endif

#ifndef SHIP_H
#define SHIP_H

class Ship : public Entity {
    private:

    public:
        Ship(int hp, int x, int y);
        ~Ship();

        virtual void attack();
        virtual void weapon();

        virtual int GetPart(int x, int y);


private:
    Ship(const Ship& Sh);
    Ship& operator=(const Ship& Sh);

};

#endif
