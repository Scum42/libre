#include "DemoGame.h"

#include "FollowMouse.h"
#include "DemoScene.h"

void DemoGame::Initialize()
{
    CreateWindow("MyGame", 800, 600, LIBRE_WINDOW_POSITION_CENTER);

    // Start on the DemoScene
    SetScene<DemoScene>();
}