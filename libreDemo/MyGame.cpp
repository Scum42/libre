#include "MyGame.h"

#include "FollowMouse.h"

void MyGame::Initialize()
{
    CreateWindow("MyGame", 800, 600, LIBRE_WINDOW_POSITION_CENTER);
    SetFramerate(60);

    Game::GetInstance();

    goStones = new GameObject();
    SpriteRendererComponent* src = goStones->AddComponent<SpriteRendererComponent>();
    goStones->AddComponent<FollowMouse>();

    stoneTex = new Texture();
    stoneTex->LoadFromFile("../res/stones.png");
    if (!stoneTex)
    {
        cout << "Texture failed to load!\n";
        cin.get();
        Kill();
    }

    stoneSprite = stoneTex->CreateSpriteFromSubsection({ 50, 50, 100, 100 });

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
