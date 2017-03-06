#pragma once

#include "Game.h"

#include <iostream>
#include <ctime>

using namespace std;
using namespace libre;

class MyGame : public Game
{
    inline void Initialize()
    {
        CreateWindow("MyGame", 800, 600, LIBRE_WINDOW_POSITION_CENTER);
        SetFramerate(60);
    }

    inline void Update()
    {

    }

    inline void Cleanup()
    {

    }
};