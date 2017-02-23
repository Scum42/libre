#ifndef LIBRE_MYGAME_H
#define LIBRE_MYGAME_H

#include "Game.h"

#include <iostream>
using namespace std;

class MyGame : public libre::Game
{
    inline virtual void Initialize() { cout << "Init\n"; Quit(); }
    inline virtual void Cleanup() { cout << "Cleanup\n"; cin.get(); }
};

#endif
