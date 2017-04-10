#pragma once

#include "libre/core/GameObject.h"
#include "libre/std/components/GroundBoxComponent.h"
#include "libre/std/components/RectRendererComponent.h"

namespace libre
{
    class GroundBoxGameObject : public GameObject
    {
    public:

        // Add components
        inline void Setup() override
        {
            mpGroundBoxComponent = AddComponent<GroundBoxComponent>();
            mpRectRendererComponent = AddComponent<RectRendererComponent>();
        }

        // The components this is packaged with because we know they're there

        inline GroundBoxComponent* GetGroundBoxComponent() { return mpGroundBoxComponent; }
        inline RectRendererComponent* GetRectRendererComponent() { return mpRectRendererComponent; }

    private:
        GroundBoxComponent* mpGroundBoxComponent;
        RectRendererComponent* mpRectRendererComponent;
    };
}
