
#include "../include/ScreenApi.h"


ScreenApi::ScreenApi(int nrows, int ncols): Screen(nrows, ncols){


};

ScreenApi::~ScreenApi(){
    ::DeleteObject(_metal);
    ::DeleteObject(_grass);
    ::DeleteObject(_water);
    ::DeleteObject(_wood);
    ::DeleteObject(_EmptyBG);

};



void ScreenApi::InitApi( HWND hwnd ){
    _hdc = GetDC( hwnd );
    _wood = ::CreateSolidBrush(0x00336699);//0x00bbggrr
    _metal = ::CreateSolidBrush(0x000000ff);
    _water = ::CreateSolidBrush(0x00fff000);
    _grass = ::CreateSolidBrush(0x0000fff0);
    _EmptyBG = ::CreateSolidBrush(0x00ffffff);
}

void ScreenApi::View(){
   for(int i=0; i<getHeight(); i++) { //Y
      for(int j=0; j<getWidth(); j++) { //X
         switch(Get(j, i)){
            case 0: (HBRUSH)::SelectObject( _hdc, _water ); break;
            case 1: (HBRUSH)::SelectObject( _hdc, _grass ); break;
            case 2: (HBRUSH)::SelectObject( _hdc, _wood ); break;
            case 3: (HBRUSH)::SelectObject( _hdc, _metal ); break;
            default: (HBRUSH)::SelectObject( _hdc, _EmptyBG ); break;
         }
         Rectangle( _hdc, j*dx, i*dy, j*dx+dx, i*dy+dy );

      }
   }
}
