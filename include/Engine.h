#include "Input.h"
#include "Keyboard.h"

#include "Screen.h"
#include "ScreenTxt.h"
#include "ScreenApi.h"

#include "Events.h"

#include "time.h"

#ifndef _WINDOWS_
    #include "windows.h"
#endif

#ifndef ENGINE_H
#define ENGINE_H


class Engine {
    private:
    Input* _I;
    Keyboard* _K;
    Events* _events;
    Screen* _S;
    ScreenTxt* _STxt;
    ScreenApi* _SApi;

    public:
        Engine();
        ~Engine();

        void Options();

        void InitScreenAPI(HWND hscreen);

        void Play(int screenT);

        void Delay(long n);

        void Swap_buff(int StartX, int StartY);


private:
    Engine(const Engine& Eng);
    Engine& operator=(const Engine& Eng);

};


#endif
