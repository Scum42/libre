#include "MyGame.h"

#include "FollowMouse.h"
#include "DemoScene.h"

void MyGame::Initialize()
{
    CreateWindow("MyGame", 800, 600, LIBRE_WINDOW_POSITION_CENTER);
    SetFramerate(60);

    // Start on the DemoScene
    SetScene<DemoScene>();
}

void MyGame::Cleanup()
{
    // No action required
}
