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
    virtual void Initialize() override;
    virtual void Cleanup() override;

    virtual void Update() override;
    virtual void Render() override;


private:
    static MyGame* spInstance;

    GameObject* goStones;

    Texture* stoneTex;
    Sprite* stoneSprite;
};