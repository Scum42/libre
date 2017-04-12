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

        inline void SetIsKinematic(bool value) { mIsKinematic = value; }
        inline bool IsKinematic() { return mIsKinematic; }

        void Initialize() override;
        void Cleanup() override;

        void Update() override;

    private:
        // libre
        bool mIsKinematic;
        float mDensity;
        float mFriction;

        // Box2D
        b2Body* mpB2Body;
    };
}
