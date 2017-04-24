#pragma once

#include "libre/util/LibreMath.h"
#include "libre/core/Component.h"

#include "Box2D/Box2D.h"

namespace libre
{
    class RigidbodyComponent : public Component
    {
    public:

        RigidbodyComponent();

        void Initialize() override;
        void Cleanup() override;

        void PhysicsUpdate() override;

        inline bool IsKinematic() { return mIsKinematic; }
        bool SetIsKinematic(bool isKinematic);

        inline float GetDensity() { return mDensity; }
        float SetDensity(float density);

        inline float GetFriction() { return mFriction; }
        float SetFriction(float friction);

    private:
        // libre
        bool mIsKinematic;
        float mDensity;
        float mFriction;

        // Box2D
        b2Body* mpB2Body;
    };
}
