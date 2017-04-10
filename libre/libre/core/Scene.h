#pragma once

#include <list>

#include "GameObject.h"

#include "Box2D/Box2D.h"

namespace libre
{
    class Game;
    class RigidbodyComponent;
    class GroundBoxComponent;

    class Scene
    {
    public:
        friend Game;
        friend RigidbodyComponent;
        friend GroundBoxComponent;

        // Constructor.
        Scene();
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

        // Destroys all objects marked for deletion. Called after PostUpdate().
        inline void EndFrame() { mGameObjects.remove_if(marked()); }

        // Calls Render on all objects in the scene.
        virtual void Render();

        // Adds a GameObject to the scene and returns a pointer to it.
        GameObject* AddGameObject();

        // Adds a GameObject to the scene named 'name' and returns a pointer to it.
        GameObject* AddGameObject(std::string name);

        // Adds a game object by class. Useful for predefined game objects.
        template <typename T>
        T* AddGameObject()
        {
            GameObject* newobj = new T();
            newobj->mpScene = this;
            mGameObjects.push_back(newobj);
            return dynamic_cast<T*>(newobj);
        }

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

        // Get scene name
        inline const std::string& GetName() { return mName; }

        // Set the pixel-per-meter ratio (and the inverse)
        void SetPixelsPerMeter(float pixelsPerMeter);

        // Set the meter-per-pixel ratio (and the inverse)
        void SetMetersPerPixel(float metersPerPixel);

        // Get the pixel-per-meter ratio
        inline float GetMeterToPixelFactor() { return mPixelsPerMeter; }

        // Get the meter-per-pixel ratio
        inline float GetPixelToMeterFactor() { return mMetersPerPixel; }

        // Get the Box2D 'world' that is being used. Meant for internal use.
        inline b2World* internal_GetB2World() { return &mB2World; }

    private:
        // Predicate for list::remove_if
        struct marked { bool operator() (GameObject* go) { return go->IsMarkedForDestruction(); } };

        // Internal initialize
        void internal_Initialize();

        // Initializes all GameObjects, then calls Startup on them
        void internal_InitializeGameObjects();

        // Internal cleanup. Destroys private data and game objects.
        void internal_Cleanup();

        // List of game objects
        std::list<GameObject*> mGameObjects;

        // Name of the scene
        std::string mName;

        // Box2D stuff
        float mPixelsPerMeter;
        float mMetersPerPixel;

        b2Vec2 mB2Gravity;
        b2World mB2World;
    };
}