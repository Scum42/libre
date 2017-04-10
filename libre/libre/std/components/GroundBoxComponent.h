#pragma once

#include "libre/core/Component.h"
#include "libre/util/LibreMath.h"

#include "Box2D/Box2D.h"

namespace libre
{
    class GroundBoxComponent : public Component
    {
    public:

        inline void SetGroundHeight(float height) { mGroundHeightInPixels = height; }

        inline float GetHeight() { return mWidthInPixels; }
        inline float GetWidth() { return mHeightInPixels; }

        void Initialize() override;
        void Startup() override;

        void Update() override;

    private:

        b2BodyDef mB2GroundBoxDef;
        b2PolygonShape mB2GroundBox;
        b2Body* mpB2GroundBoxBody;

        b2World* mpB2WorldFromScene;

        float mWidthInPixels;
        float mHeightInPixels;

        float mGroundHeightInPixels;
    };
}