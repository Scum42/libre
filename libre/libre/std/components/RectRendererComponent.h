#pragma once

#include "libre/core/Component.h"
#include "libre/util/Color.h"

namespace libre
{
    class RectRendererComponent : public Component
    {
    public:

        inline void SetWidth(float width) { mWidth = width; }
        inline void SetHeight(float height) { mHeight = height; }
        inline void SetColor(Color c) { mDrawColor = c; }

        inline float GetWidth() { return mWidth; }
        inline float GetHeight() { return mHeight; }
        inline Color GetColor() { return mDrawColor; }

        void Render() override;

    private:
        float mWidth;
        float mHeight;
        Color mDrawColor;
    };
}