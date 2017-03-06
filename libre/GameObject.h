#pragma once

#include <vector>

#include "LibreMath.h"

namespace libre
{
    class Component;

    class GameObject
    {
    public:
        GameObject();
        inline ~GameObject() { Cleanup(); }

        // Calls Initialize on all components.
        void Initialize();

        // Calls Cleanup on all components, then destroys them.
        void Cleanup();

        // Calls PreUpdate on all components.
        void PreUpdate();

        // Calls Update on all components.
        void Update();

        // Calls PostUpdate on all components.
        void PostUpdate();

        // Calls Render on all components.
        void Render();

        // Returns the parent of this game object. Returns nullptr if it is a top level game object.
        GameObject* GetParent() { return mpParent; }

        // Adds a component to this GameObject. From this point forward, it's the GameObject's job to clean it up.
        Component* AddComponent(Component* component);

        // Get component by type. Returns nullptr if no such component was found.
        template <typename T>
        inline T* GetComponent()
        {
            type_info info = typeid(T);
            //TypeID id = TypeIDUtility::Get<T>();

            for (Component* c : mComponents)
            {
                if (typeid(*c) == info) return c;
            }

            return nullptr;
        }

        // The local transform of the object.
        Transform transform;

        // The global transform of the object. Read-only.
        Transform GetGlobalTransform();

    private:
        GameObject* mpParent;
        std::vector<Component*> mComponents;
    };
}