#ifndef SCREEN_H
    #include "Screen.h"
#endif

#ifndef _WINDOWS_
    #include "windows.h"
#endif

#ifndef SCREENAPI_H
#define SCREENAPI_H

/*enum colors{
    metal = 0,
    grass= 0,
    water= 0,
    wood= 0,

};*/


class ScreenApi : public Screen{
private:
    HDC _hdc;
    HBRUSH _metal;
    HBRUSH _grass;
    HBRUSH _water;
    HBRUSH _wood;
    HBRUSH _EmptyBG;
    int dx = 18;
    int dy = 18;

public:
    ScreenApi(int nrows, int ncols);
    ~ScreenApi();

    virtual void View();
    void InitApi(HWND hwnd);

private:
    ScreenApi(const ScreenApi& Sapi);
    ScreenApi& operator=(const ScreenApi& Sapi);


};


#endif
