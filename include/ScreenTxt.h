#ifndef SCREEN_H
    #include "Screen.h"
#endif

#ifndef _WINDOWS_
    #include "windows.h"
#endif

#include <iostream>

#ifndef SCREENTXT_H
#define SCREENTXT_H

class ScreenTxt : public Screen{

public:
    ScreenTxt(int nrows, int ncols);
    ~ScreenTxt();

    virtual void View();

private:
    ScreenTxt(const ScreenTxt& Stxt);
    ScreenTxt& operator=(const ScreenTxt& Stxt);

};

#endif
