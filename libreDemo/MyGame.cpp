#include "MyGame.h"

#include "GameObject.h"
#include "SpriteRendererComponent.h"
#include "Texture.h"

#include "FollowMouse.h"

MyGame* MyGame::spInstance = nullptr;

MyGame* MyGame::GetInstance()
{
    if (!spInstance) spInstance = new MyGame();
    return spInstance;
}

void MyGame::Initialize()
{
    CreateWindow("MyGame", 800, 600, LIBRE_WINDOW_POSITION_CENTER);
    SetFramerate(60);

    goStones = new GameObject();
    SpriteRendererComponent* src = dynamic_cast<SpriteRendererComponent*>(goStones->AddComponent(new SpriteRendererComponent(GetWindow()->GetRenderer())));
    goStones->AddComponent(new FollowMouse());

    stoneTex = new Texture();
    stoneTex->LoadFromFile(GetWindow()->GetRenderer(), "../res/stones.png");
    if (!stoneTex)
    {
        cout << "texture is null";
        cin.get();
        Kill();
    }

    stoneSprite = stoneTex->CreateSpriteFromSubsection({ 0, 0, 100, 100 });

    src->SetSprite(stoneSprite);
}



void MyGame::Cleanup()
{
    delete goStones;
    goStones = nullptr;

    delete stoneTex;
    stoneTex = nullptr;

    delete stoneSprite;
    stoneSprite = nullptr;
}

void MyGame::Update()
{
    goStones->Update();
}

void MyGame::Render()
{
    goStones->Render();
}
