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
