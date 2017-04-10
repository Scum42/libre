#pragma once

#include "libre/core/GameObject.h"
#include "libre/std/components/GroundBoxComponent.h"

namespace libre
{
    class GroundBoxGameObject : public GameObject
    {
    public:

        // Add components
        inline void Setup() override
        {
            mpGroundBoxComponent = AddComponent<GroundBoxComponent>();
        }

        // The component this is packaged with because we know it's there
        inline GroundBoxComponent* GetGroundBoxComponent() { return mpGroundBoxComponent; }
        
    private:
        GroundBoxComponent* mpGroundBoxComponent;
    };
}
