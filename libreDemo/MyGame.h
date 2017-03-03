#pragma once

#include "Game.h"

#include <iostream>

using namespace std;
using namespace libre;

class MyGame : public Game
{
    inline void Initialize()
    {
        cout << "Init\n";
    }

    inline void Update()
    {
        cout << "Update\n";
        Quit();
    }

    inline void Cleanup()
    {
        cout << "Cleanup\n";
        cin.get();
    }
};