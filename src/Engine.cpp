#include "../include/Engine.h"

Engine::Engine(){
    Options();
};
Engine::~Engine(){
    if(_K) delete _K;
    if(_SApi) delete _SApi;
    if(_STxt) delete _STxt;
    if(_events) delete _events;
};


void Engine::Delay(long n)
{
   long t0 = clock();
   while( clock()-t0 < n ) ;
}

void Engine::Options(){
    _events = new Events(100,50);

    _STxt = new ScreenTxt(100,50);
    _SApi = new ScreenApi(100,50);

    _K = new Keyboard();

}


void Engine::InitScreenAPI(HWND hscreen){
    _SApi->InitApi(hscreen);
}

void Engine::Play(int screenT){
    srand(time(NULL));
    if(screenT == 1)
        _S = _STxt; //ekran tekstowy
    else if(screenT == 2)
        _S = _SApi; //ekran graficzny
    else
        _S = 0;

    _I = _K; //klawiatura

    if(_S!= nullptr){
    Swap_buff(0,0);
    _S->View();
    Delay(1000);

    _events->Player1();

    bool end_game=0;
    while(true){
        if(!end_game){

            _I->translateKeys();
            _events->PlayerMove(_I->getKeys());

            _events->Update();

            if(_events->isEnd())
                end_game = 1;

            Swap_buff(0,0);
            _S->View();
            Delay(100);
        }else{
            if(_events->isEnd() == 1)
                _events->fill(0);
            else
                _events->fill(1);
            Swap_buff(0,0);
            _S->View();
        }
    }

    }

};

void Engine::Swap_buff(int StartX, int StartY){
    for(int i=0;i<_S->getHeight();i++)
        for(int j=0;j<_S->getWidth();j++)
            if( (StartX+j)<_events->getWidth() && (StartY+i)<_events->getHeight() ){
                    _S->Set( j, i, _events->Get(StartX+j, StartY+i) ); //wszystkie eventy
                }
}


