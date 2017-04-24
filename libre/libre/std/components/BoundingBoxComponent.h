#pragma once

#include "libre/core/Component.h"
#include "libre/util/LibreMath.h"

namespace libre
{
    class BoundingBoxComponent : public Component
    {
    public:

        inline float SetWidth(float w) { return SetDimensions(w, GetHeight()).x; }
        inline float SetHeight(float h) { return SetDimensions(GetWidth(), h).y; }
        inline float SetHalfWidth(float hw) { return SetExtents(hw, GetHalfHeight()).x; }
        inline float SetHalfHeight(float hh) { return SetExtents(GetHalfWidth(), hh).y; }

        inline float GetWidth() { return mDimensions.x; }
        inline float GetHeight() { return mDimensions.y; }
        inline float GetHalfWidth() { return mExtents.x; }
        inline float GetHalfHeight() { return mExtents.y; }

        Vector2f SetDimensions(Vector2f dim);
        inline Vector2f SetDimensions(float w, float h) { return SetDimensions(Vector2f(w, h)); }

        Vector2f SetExtents(Vector2f ext);
        inline Vector2f SetExtents(float hw, float hh) { return SetDimensions(hw, hh); }

        inline Vector2f GetDimensions() { return mDimensions; }
        inline Vector2f GetExtents() { return mExtents; }

    private:
        Vector2f mDimensions;
        Vector2f mExtents;
    };
}