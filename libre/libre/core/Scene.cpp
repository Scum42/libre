#include "Scene.h"

#include <typeinfo>

#include "libre/util/Time.h"
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

void libre::Scene::internal_Initialize()
{
    mName = typeid(this).name();
}

void libre::Scene::internal_InitializeGameObjects()
{
    // Init first
    for (GameObject* go : mGameObjects) go->Initialize();
    // Then startup
    for (GameObject* go : mGameObjects) go->Startup();
}

void libre::Scene::internal_Cleanup()
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

libre::Scene::Scene() :
    mB2Gravity(0.0f, 9.8f),
    mB2World(mB2Gravity)
{}

libre::Scene::~Scene()
{
    Cleanup();
    internal_Cleanup();
}

void libre::Scene::PhysicsUpdate()
{
    mB2World.Step(Time::deltaTime, 8, 3);

    for (auto iter : mGameObjects)
    {
        iter->PhysicsUpdate();
    }
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

    mGameObjects.push_back(gop);
    return gop;
}

libre::GameObject* libre::Scene::AddGameObject(std::string name)
{
    GameObject* gop = new GameObject(name);

    mGameObjects.push_back(gop);
    return gop;
}