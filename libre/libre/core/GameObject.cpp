#include "GameObject.h"

#include "Component.h"

libre::GameObject::GameObject()
{
    mpParent = nullptr;
    mName = "GameObject";
    mIsMarkedForDeath = false;
    transform = Transform();
    Setup();
}

libre::GameObject::GameObject(std::string name)
{
    mpParent = nullptr;
    mName = name;
    mIsMarkedForDeath = false;
    transform = Transform();
    Setup();
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

void libre::GameObject::Startup()
{
    for (Component* c : mComponents)
    {
        c->Startup();
    }
}

void libre::GameObject::PhysicsUpdate()
{
    for (Component* c : mComponents)
    {
        c->PhysicsUpdate();
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
    Transform composite = transform;
    GameObject* parent = this;

    // Step up the parents until we hit an object without a parent
    while (parent = parent->GetParent())
    {
        composite += parent->transform;
    }
    
    return composite;
}
