#include "GameObject.h"

#include "Component.h"

libre::GameObject::GameObject()
{
    mpParent = nullptr;
    transform = Transform();
}

void libre::GameObject::Initialize()
{
    for (Component* c : mComponents)
    {
        c->Initialize();
    }
}

void libre::GameObject::Cleanup()
{
    for (int i = 0; i < mComponents.size(); i++)
    {
        mComponents[i]->Cleanup();
        delete mComponents[i];
        mComponents[i] = nullptr;
    }

    mComponents.clear();
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

template <typename T>
T* libre::GameObject::AddComponent()
{
    T* newComp = new T();
    mComponents.push_back(newComp);
    newComp->mpGameObject = this;
    return newComp;
}

libre::Transform libre::GameObject::GetGlobalTransform()
{
    // TODO: GetGlobalTransform
    return transform;
}
