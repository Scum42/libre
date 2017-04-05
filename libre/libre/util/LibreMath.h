#pragma once

#include <cstdlib>
#include <cmath>

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
        inline Transform()
        {
            position.x = 0.0f;
            position.y = 0.0f;

            scale.x = 0.0f;
            scale.y = 0.0f;

            rotation = 0.0f;
        }

        Vector2f position;
        Vector2f scale;
        float rotation;
    };

    inline int Round(double in) { return (int)round(in); }
    inline int Round(float in) { return (int)round(in); }
    inline int Floor(double in) { return (int)floor(in); }
    inline int Floor(float in) { return (int)floor(in); }
    inline int Ceil(double in) { return (int)ceil(in); }
    inline int Ceil(float in) { return (int)ceil(in); }
}