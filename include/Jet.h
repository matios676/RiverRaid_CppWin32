#ifndef ENTITY_H
    #include "Entity.h"
#endif

#ifndef JET_H
#define JET_H

class Jet : public Entity {

    public:
        Jet(int hp, int x, int y);
        ~Jet();

        virtual void attack();
        virtual void weapon();

        virtual int GetPart(int x, int y);

private:
    Jet(const Jet& j);
    Jet& operator=(const Jet& j);

};

#endif
