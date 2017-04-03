#pragma once

#include "libre/util/LibreMath.h"

namespace libre
{
    class Texture;

    class Sprite
    {
    public:
        inline Sprite() : Sprite(nullptr, { 0,0,0,0 }) {}
        inline Sprite(Texture* tex) : Sprite(tex, { 0,0,0,0 }) {}
        Sprite(Texture* tex, Recti rect);

        inline Texture* GetTexture() { return mpTexture; }
        inline Recti GetRect() { return mSpriteRect; }

    private:
        Texture* mpTexture;
        Recti mSpriteRect;
    };
}