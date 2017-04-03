#include "GameObject.h"

#include "Component.h"

libre::GameObject::GameObject()
{
    mpParent = nullptr;
    mName = "GameObject";
    mIsMarkedForDeath = false;
    transform = Transform();
}

libre::GameObject::GameObject(std::string name)
{
    mpParent = nullptr;
    mName = name;
    mIsMarkedForDeath = false;
    transform = Transform();
}

libre::GameObject::~GameObject()
{
    for (unsigned int i = 0; i < mComponents.size(); i++)
    {
        if (mComponents[i] == nullptr) continue;

        mComponents[i]->Cleanup();
        delete mComponents[i];
        mComponents[i] = nullptr;
    }

    mComponents.clear();
}

void libre::GameObject::Initialize()
{
    for (Component* c : mComponents)
    {
        c->Initialize();
    }
}

void libre::GameObject::PreUpdate()
{
    for (Component* c : mComponents)
    {
        c->PreUpdate();
    }
}

void libre::GameObject::Update()
{
    for (Component* c : mComponents)
    {
        c->Update();
    }
}

void libre::GameObject::PostUpdate()
{
    for (Component* c : mComponents)
    {
        c->PostUpdate();
    }
}

void libre::GameObject::Render()
{
    for (Component* c : mComponents)
    {
        c->Render();
    }
}

libre::Transform libre::GameObject::GetGlobalTransform()
{
    // TODO: GetGlobalTransform
    return transform;
}
