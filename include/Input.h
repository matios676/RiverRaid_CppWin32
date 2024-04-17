
#ifndef INPUT_H
#define INPUT_H

#define GORA 0
#define DOL 1
#define LEWO 2
#define PRAWO 3
#define UZBROJENIE 4

class Input {
    private:
    bool keys[5];
    //bool Left, Right, Forward, Backwards;
    //bool Weapon;


    public:
        Input();
        ~Input();

        bool* getKeys();
        void  setKey(int index, bool state);

        virtual void translateKeys() = 0;

    private:
    Input(const Input& i);
    Input& operator=(const Input& i);

};

#endif
