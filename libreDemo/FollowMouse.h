#pragma once

#include "Component.h"

using namespace libre;

class FollowMouse : public Component
{
    DEFINE_TYPE_ID(FollowMouse)

public:

    void Update() override;
};