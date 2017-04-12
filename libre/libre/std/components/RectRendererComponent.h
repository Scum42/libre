#pragma once

#include "libre/core/Component.h"
#include "libre/util/Color.h"

namespace libre
{
    class RectRendererComponent : public Component
    {
    public:

        inline void SetWidth(float width) { mWidth = width; mHalfWidth = width * 0.5f; }
        inline void SetHeight(float height) { mHeight = height; mHalfHeight = height * 0.5f; }
        inline void SetColor(Color c) { mDrawColor = c; }
        inline void SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255) { mDrawColor = Color(r, g, b, a); }

        inline float GetWidth() { return mWidth; }
        inline float GetHeight() { return mHeight; }
        inline Color GetColor() { return mDrawColor; }

        void Render() override;

    private:
        float mWidth;
        float mHalfWidth;
        float mHeight;
        float mHalfHeight;
        Color mDrawColor;
    };
}