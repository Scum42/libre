#ifndef LIBRE_MATH_H
#define LIBRE_MATH_H

namespace libre
{
    template <typename T>
    struct Point
    {
        T x;
        T y;
    };

    template <typename T>
    struct Rect
    {
        T x;
        T y;
        T w;
        T h;
    };

    typedef Point<int> PointInt;
    typedef Point<float> PointFloat;
    typedef Point<double> PointDouble;

    typedef Rect<int> RectInt;
    typedef Rect<float> RectFloat;
    typedef Rect<double> RectDouble;
}

#endif