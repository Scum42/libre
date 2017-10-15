#pragma once

#include "libre/core/Component.h"
#include "libre/core/Sprite.h"

using namespace libre;

class FollowMouse : public Component
{
public:

    void Startup() override;
    void Update() override;

private:

    // Cache SpriteRendererComponent
    Sprite* sprite;
};