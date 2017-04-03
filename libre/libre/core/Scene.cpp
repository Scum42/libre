#include "Scene.h"

#include "GameObject.h"

libre::Scene::~Scene()
{
    for (auto i = mGameObjects.begin();
         i != mGameObjects.end();
         i++)
    {
        delete *i;
        *i = nullptr;
    }

    mGameObjects.clear();
}

void libre::Scene::PreUpdate()
{
    for (auto iter : mGameObjects)
    {
        iter->PreUpdate();
    }
}

void libre::Scene::Update()
{
    for (auto iter : mGameObjects)
    {
        iter->Update();
    }
}

void libre::Scene::PostUpdate()
{
    for (auto iter : mGameObjects)
    {
        iter->PostUpdate();
    }
}
