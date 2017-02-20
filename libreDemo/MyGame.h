#ifndef LIBRE_MYGAME_H
#define LIBRE_MYGAME_H

#include "Game.h"

#include <iostream>
using namespace std;

class MyGame : public libre::Game
{
    virtual void Initialize() { cout << "Init\n"; }
    virtual void Cleanup() { cout << "Cleanup\n"; }
};

#endif
