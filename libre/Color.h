#pragma once

#include <cstdint>

typedef uint8_t Uint8;

namespace libre
{
    struct Color
    {
        inline Color() {}
        inline Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255)
        {
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
        }

        Uint8 r, g, b, a;
    };
}