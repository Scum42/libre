#pragma once

namespace libre
{
    class GameObject;

    class Component
    {
    public:
        friend GameObject;

        inline virtual void Initialize() {}
        inline virtual void Cleanup() {}

        inline virtual void PreUpdate() {}
        inline virtual void Update() {}
        inline virtual void PostUpdate() {}

        inline virtual void Render() {}

        inline GameObject* GetGameObject() { return mpGameObject; }

    private:
        GameObject* mpGameObject;
    };
}