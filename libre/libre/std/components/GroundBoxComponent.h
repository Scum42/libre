#pragma once

#include "libre/core/Component.h"
#include "libre/util/LibreMath.h"

#include "Box2D/Box2D.h"

namespace libre
{
    class GroundBoxComponent : public Component
    {
    public:

        inline void SetGroundHeight(float height) { mGroundHeight = height; }

        inline float GetHeight() { return mWidth; }
        inline float GetWidth() { return mHeight; }

        void Initialize() override;
        void Startup() override;

    private:

        b2BodyDef mB2GroundBoxDef;
        b2PolygonShape mB2GroundBox;
        b2Body* mpB2GroundBoxBody;

        b2World* mpB2WorldFromScene;

        float mWidth;
        float mHeight;

        float mGroundHeight;
    };
}