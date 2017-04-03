#pragma once

#include <list>

#include "GameObject.h"

namespace libre
{
    class Scene
    {
    public:

        // Constructor.
        inline Scene() { InternalInitialize(); }
        // Destructor. Destroys all game objects.
        inline ~Scene() { Cleanup(); InternalCleanup(); }

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

        // Destroys all objects marked for deletion.
        inline void EndFrame() { mGameObjects.remove_if(marked()); }

        // Calls Render on all objects in the scene.
        virtual void Render();

        // Adds a GameObject to the scene and returns a pointer to it.
        GameObject* AddGameObject();

        // Adds a GameObject to the scene named 'name' and returns a pointer to it.
        GameObject* AddGameObject(std::string name);

        // Adds a GameObject to the scene named 'name,' attaches a component of type T, and returns a pointer to the GameObject.
        template <typename T>
        inline GameObject* AddGameObjectWithComponent(std::string name)
        {
            GameObject* gop = AddGameObject(name);
            gop->AddComponent<T>();
            return gop;
        }

        // Adds a GameObject to the scene, attaches a component of type T, and returns a pointer to the GameObject.
        template <typename T>
        inline GameObject* AddGameObjectWithComponent()
        {
            GameObject* gop = AddGameObject();
            gop->AddComponent<T>();
            return gop;
        }

        // Returns the first GameObject named 'name' in the list. Returns nullptr if no such object could be found.
        GameObject* FindGameObject(const std::string& name);

    private:
        // Predicate for list::remove_if
        struct marked { bool operator() (GameObject* go) { return go->IsMarkedForDestruction(); } };

        // Internal init. Initializes private data.
        inline void InternalInitialize() {}

        // Internal cleanup. Destroys private data and game objects.
        void InternalCleanup();

        std::list<GameObject*> mGameObjects;
    };
}