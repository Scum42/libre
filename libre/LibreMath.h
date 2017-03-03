#pragma once

#include <cstdlib>

namespace libre
{
    template <typename T>
    struct Vector2
    {
        T x;
        T y;

        inline float lengthSq() { return x*x + y*y; }
        inline float length() { return sqrt(lengthSq()); }

        inline Vector2<T>& normalize() { return *this /= length(); }
    };

    template <typename T>
    struct Rect
    {
        T x;
        T y;
        T w;
        T h;
    };

    typedef Vector2<int> Vector2i;
    typedef Vector2<float> Vector2f;
    typedef Vector2<double> Vector2d;

    typedef Rect<int> Recti;
    typedef Rect<float> Rectf;
    typedef Rect<double> Rectd;

    struct Transform
    {
        Vector2f position;
        Vector2f scale;
        float rotation;
    };
}