#include "MyGame.h"

MyGame* MyGame::mspInstance = nullptr;


MyGame* MyGame::GetInstance()
{
    if (!mspInstance) mspInstance = new MyGame();
    return mspInstance;
}

void MyGame::Initialize()
{
    CreateWindow("MyGame", 800, 600, LIBRE_WINDOW_POSITION_CENTER);
    SetFramerate(60);
}

void MyGame::Cleanup()
{}
