#pragma once

#include "libre/core/Component.h"

#include "Box2D/Box2D.h"

namespace libre
{
    class RigidbodyComponent : public Component
    {
    public:

        inline void SetIsKinematic(bool value) { mIsKinematic = value; }
        inline bool IsKinematic() { return mIsKinematic; }

        void Update() override;

        void Initialize() override;

    private:
        bool mIsKinematic;
        float mDensity;
        float mFriction;

        // Box2D
        b2Body* mpB2Body;
    };
}
