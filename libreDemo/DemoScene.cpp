#include "DemoScene.h"
#include "FollowMouse.h"
#include "RotateDegPerSec.h"

#include "libre/librestd.h"

void DemoScene::Initialize()
{
    GameObject* goStones = AddGameObject("stones");
    goStones->AddComponent<SpriteRendererComponent>()->SetSprite("../res/stones.png", { 50, 50, 150, 150 });
    goStones->AddComponent<RotateDegPerSec>()->SetSpeed(20.0f);
    goStones->AddComponent<RigidbodyComponent>()->SetIsKinematic(true);
    goStones->AddComponent<FollowMouse>();

    GameObject* goGround = AddGameObject("ground");
    goGround->AddComponent<GroundBoxComponent>()->SetGroundHeight(50.0f);
    goGround->AddComponent<RectRendererComponent>();

    GameObject* goTest = AddGameObject("test");
    goTest->AddComponent<SpriteRendererComponent>()->SetSprite("../res/stones.png", { 100, 100, 200, 200 });
    goTest->transform.position = { 400, 200 };
    goTest->transform.rotation = 20.0f;
    
    RigidbodyComponent* rb = goTest->AddComponent<RigidbodyComponent>();

}
