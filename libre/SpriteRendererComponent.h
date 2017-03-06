#pragma once

#include "Component.h"

namespace libre
{
    class SpriteRendererComponent : public Component
    {
        inline virtual TypeID GetTypeID() { return TypeIDUtility::Get<SpriteRendererComponent>(); }
    };
}