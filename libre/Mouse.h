#pragma once

#include "LibreMath.h"

namespace libre
{
    class Mouse
    {
        friend class Game;

    public:
        static inline Vector2i GetPosition() { return mPos; }

    private:
        static Vector2i mPos;
    };
}