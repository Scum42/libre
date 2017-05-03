#include "DemoScene.h"
#include "FollowMouse.h"
#include "RotateDegPerSec.h"

#include "libre/librestd.h"

void DemoScene::Initialize()
{
    SpriteRendererComponent* spr = nullptr;

    GameObject* goStones = AddGameObject("stones");
    spr = goStones->AddComponent<SpriteRendererComponent>();
    spr->SetSprite("../res/stones.png", { 50, 50, 100, 100 });
    spr->AddBoundingBoxComponent();

    goStones->AddComponent<RigidbodyComponent>()->SetIsKinematic(true);
    goStones->AddComponent<FollowMouse>();
    goStones->AddComponent<RotateDegPerSec>()->SetSpeed(20.0f);

    GameObject* goGround = AddGameObject("ground");
    goGround->AddComponent<GroundBoxComponent>()->SetGroundHeight(50.0f);
    goGround->AddComponent<ScreenEdgeWallComponent>();
    goGround->AddComponent<RectRendererComponent>();

    GameObject* goTest = AddGameObject("test");
    goTest->AddComponent<RigidbodyComponent>();
    spr = goTest->AddComponent<SpriteRendererComponent>();
    spr->SetSprite("../res/stones.png", { 100, 100, 200, 200 });
    spr->AddBoundingBoxComponent();
    
    goTest->transform.position = { 400, 200 };
    goTest->transform.rotation = 20.0f;
    
    GameObject* goTest2 = AddGameObject("test");
    goTest2->AddComponent<RigidbodyComponent>();
    spr = goTest2->AddComponent<SpriteRendererComponent>();
    spr->SetSprite("../res/stones.png", { 100, 100, 200, 200 });
    spr->AddBoundingBoxComponent();

    goTest2->transform.position = { 400, 100 };
    goTest2->transform.rotation = 10.0f;
}
