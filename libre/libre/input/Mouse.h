#pragma once

#include <bitset>
#include "libre/util/LibreMath.h"

namespace libre
{
    struct MouseState
    {
        Vector2i position;
        std::bitset<3> buttons;
    };

    class Mouse
    {
        friend class Game;

    public:

        enum MouseButton
        {
            MOUSE_LEFT = 0,
            MOUSE_RIGHT,
            MOUSE_MIDDLE
        };

        static inline Vector2i GetPosition() { return mState.position; }

    private:
        static MouseState mState;
        static MouseState mLastState;
    };
}