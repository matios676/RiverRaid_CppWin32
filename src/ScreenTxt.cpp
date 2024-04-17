#include "../include/ScreenTxt.h"


ScreenTxt::ScreenTxt(int nrows, int ncols) : Screen(nrows, ncols) {

};
ScreenTxt::~ScreenTxt(){

};


void ScreenTxt::View(){

    system("cls");
    std::cout<<"+";
    for(int i=0;i<getWidth();i++)
        std::cout<<"-";
    std::cout<<"+";

    std::cout<<std::endl;

    for(int i=0;i<getHeight();i++){
            std::cout<<"|";

        for(int j=0;j<getWidth();j++){
            switch(Get(j,i)){
                case 0: std::cout << " "; break;
                case 1: std::cout << "*"; break;
                case 2: std::cout << "="; break;
                case 3: std::cout << "o"; break;
                default: std::cout << Get(j,i);
            }
        }

        std::cout<<"|";
        std::cout<<std::endl;
    }

    std::cout<<"+";
    for(int i=0;i<getWidth();i++)
        std::cout<<"-";
    std::cout<<"+";
    std::cout<<std::endl;

    //system("PAUSE");

    /*std::cout<<getWidth();
    for(int i=0;i<getWidth();i++){
        //std::cout<<Get(0,i);
    }*/

}
