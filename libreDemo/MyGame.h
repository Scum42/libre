#ifndef MYGAME_H
#define MYGAME_H

#include "Game.h"

#include <iostream>
using namespace std;

class MyGame : public libre::Game
{
	virtual void Initialize() { cout << "Init"; }
	virtual void Cleanup() { cout << "Cleanup"; }
};

#endif