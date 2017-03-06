#pragma once

#include "TypeID.h"

namespace libre
{
    class GameObject;

    class Component
    {
    public:
        friend GameObject;

        inline virtual TypeID GetTypeID() const = 0;

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