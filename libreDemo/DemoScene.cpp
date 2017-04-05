#include "DemoScene.h"
#include "FollowMouse.h"

void DemoScene::Initialize()
{
    GameObject* goStones = AddGameObject("stones");
    goStones->AddComponent<SpriteRendererComponent>()->SetSprite("../res/stones.png", { 50, 50, 100, 100 });
    goStones->AddComponent<FollowMouse>();
}
