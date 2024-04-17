
#ifndef ENTITY_H
#define ENTITY_H


class Entity {
    private:
    int _Type;
    int _Health;
    bool Alive = 0;
    int _x;
    int _y;
    int _Size;


    public:
        Entity(int hp, int x, int y, int Size, int type);
        ~Entity();

        int GetType();
        bool isAlive();
        void Destroy();

        int GetSize();
        int GetX();
        int GetY();
        void SetPos(int x, int y);

        int GetHP();


        virtual void attack() = 0;
        virtual void weapon() = 0;

        virtual int GetPart(int x, int y) = 0;

private:
    Entity(const Entity& Ent);
    Entity& operator=(const Entity& Ent);

};

#endif
