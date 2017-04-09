#include "DemoGame.h"

#include "FollowMouse.h"
#include "DemoScene.h"

void DemoGame::Initialize()
{
    CreateWindow("MyGame", 800, 600, LIBRE_WINDOW_POSITION_CENTER);
    SetFramerate(60);

    // Start on the DemoScene
    SetScene<DemoScene>();
}

void DemoGame::Cleanup()
{
    // No action required
}
