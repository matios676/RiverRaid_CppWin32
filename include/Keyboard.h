#ifndef INPUT_H
    #include "Input.h"
#endif // INPUT_H

#ifndef _WINDOWS_
    #include "windows.h"
#endif // _WINDOWS_

#ifndef KEYBOARD_H
#define KEYBOARD_H


class Keyboard : public Input {
    private:

    public:
        Keyboard();
        ~Keyboard();

        virtual void translateKeys();

    private:
    Keyboard(const Keyboard& k);
    Keyboard& operator=(const Keyboard& k);

};

#endif
