#include "Scene.h"

#include "GameObject.h"

libre::GameObject* libre::Scene::FindGameObject(const std::string& name)
{
    for (auto iter : mGameObjects)
    {
        if (iter->GetName().compare(name))
            return iter;
    }

    return nullptr;
}

void libre::Scene::InternalCleanup()
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

void libre::Scene::Render()
{
    for (auto iter : mGameObjects)
    {
        iter->Render();
    }
}

libre::GameObject* libre::Scene::AddGameObject()
{
    GameObject* gop = new GameObject();
    gop->mpScene = this;

    mGameObjects.push_back(gop);
    return gop;
}

libre::GameObject* libre::Scene::AddGameObject(std::string name)
{
    GameObject* gop = new GameObject(name);
    gop->mpScene = this;

    mGameObjects.push_back(gop);
    return gop;
}
