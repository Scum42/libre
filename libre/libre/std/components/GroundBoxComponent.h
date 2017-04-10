#pragma once

#include "libre/core/Component.h"

#include "Box2D/Box2D.h"

namespace libre
{
    class GroundBoxComponent : public Component
    {
    public:

        void Initialize() override;

    private:

        b2BodyDef mB2GroundBoxDef;
        b2PolygonShape mB2GroundBox;
        b2Body* mpB2GroundBoxBody;

        b2World* mpB2WorldFromScene;
    };
}