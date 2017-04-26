#pragma once

#include "libre\core\Component.h"
#include "libre\core\Game.h"
#include "libre\core\Scene.h"
#include "Box2D\Box2D.h"

namespace libre
{
    class ScreenEdgeWallComponent : public Component
    {
    public:
        void Initialize() override;
        void Cleanup() override;

    private:
        b2Body *mpB2bodies[4];
    };
}
