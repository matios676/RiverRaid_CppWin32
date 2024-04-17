
#include "Canvas.h"


#ifndef SCREEN_H
#define SCREEN_H


class Screen : public Canvas{
protected:

public:
    Screen(int rows, int cols);
    virtual ~Screen();
    virtual void View() = 0;


private:
    Screen(const Screen& Sc);
    Screen& operator=(const Screen& Sc);


};


#endif
