#pragma once

#include <list>

//#include "GameObject.h"

namespace libre
{
    class GameObject;

    class Scene
    {
    public:

        // Constructor.
        inline Scene() {}
        // Destructor. Destroys all game objects.
        ~Scene();

        // This is where GameObjects are added to the scene.
        virtual void Initialize() = 0;

        // This is where anything created in Initialize must be destroyed. GameObjects in the list are cleaned up internally.
        inline virtual void Cleanup() {}

        // Calls PreUpdate on all objects in the scene.
        virtual void PreUpdate();

        // Calls Update on all objects in the scene.
        virtual void Update();

        // Calls PostUpdate on all objects in the scene.
        virtual void PostUpdate();
    private:
        std::list<GameObject*> mGameObjects;
    };
}