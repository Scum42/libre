#pragma once

namespace libre
{
    class GameObject;

    class Component
    {
    public:
        friend GameObject;

        // Initialize the component
        inline virtual void Initialize() {}
        // Clean up the component
        inline virtual void Cleanup() {}

        // Called when the scene starts, after all components have been Initialize()d
        inline virtual void Startup() {}

        // Logic that happens when physics updates (meant for physics ONLY)
        inline virtual void PhysicsUpdate() {}
        // Logic that should happen at the beginning of the frame
        inline virtual void PreUpdate() {}
        // Update logic
        inline virtual void Update() {}
        // Logic that should happen at the end of the frame
        inline virtual void PostUpdate() {}

        // Used for rendering components, or anything that cares about doing things when the scene renders.
        inline virtual void Render() {}

        // Get the GameObject that this Component is attached to.
        inline GameObject* GetGameObject() { return mpGameObject; }

    private:
        GameObject* mpGameObject;
    };
}