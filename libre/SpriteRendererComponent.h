#pragma once

#include "Component.h"

namespace libre
{
    class SpriteRendererComponent : public Component
    {
        virtual TypeID GetTypeID() override { return TypeIDUtility::Get<SpriteRendererComponent>(); }
    };
}