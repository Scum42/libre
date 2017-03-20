#pragma once

#include "Game.h"
#include "GameObject.h"

#include <iostream>
#include <ctime>

using namespace std;
using namespace libre;

class MyGame : public Game
{
protected:
    virtual void Initialize() override;
    virtual void Cleanup() override;

    virtual void Update() override;
    virtual void Render() override;

private:
    GameObject* goStones;

    Texture* stoneTex;
    Sprite* stoneSprite;
};