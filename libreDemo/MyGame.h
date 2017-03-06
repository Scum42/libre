#pragma once

#include "Game.h"
#include "GameObject.h"

#include <iostream>
#include <ctime>

using namespace std;
using namespace libre;

class MyGame : public Game
{
public:
    static MyGame* GetInstance();

protected:
    void Initialize();
    void Cleanup();

private:
    static MyGame* mspInstance;

    GameObject* goStones;
};