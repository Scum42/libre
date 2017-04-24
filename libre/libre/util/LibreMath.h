#pragma once

#include <cstdlib>
#include <cmath>

#include "Box2D\Box2D.h"

namespace libre
{
    const float PI = 3.141592653589793f;
    const float PI_INV = 1.0f / PI;
    const float TAU = PI * 2.0f;
    const float TAU_INV = 1.0f / TAU;
    const float DEG_TO_RAD_FACTOR = PI / 180.0f;
    const float RAD_TO_DEG_FACTOR = 180.0f / PI;
    const float METER_TO_PIXEL_FACTOR = 100.0f;
    const float PIXEL_TO_METER_FACTOR = 1.0f / METER_TO_PIXEL_FACTOR;

    template <typename T>
    struct Vector2
    {
        inline Vector2() { x = static_cast<T>(0); y = static_cast<T>(0); }
        inline Vector2(T x, T y) { this->x = x; this->y = y; }

        // Conversion constructors
        template <typename U>
        inline Vector2(const Vector2<U>& other)
        {
            x = static_cast<T>(other.x);
            y = static_cast<T>(other.y);
        }

        inline Vector2(const b2Vec2& other)
        {
            x = other.x;
            y = other.y;
        }

        T x;
        T y;

        inline float lengthSq() { return x*x + y*y; }
        inline float length() { return sqrt(lengthSq()); }

        inline Vector2<T>& normalize()
        {
            return *this / length(); 
        }

        inline Vector2<T> operator-() const
        {
            return Vector2<T>(-x, -y);
        }

        inline Vector2<T> operator-(const Vector2<T>& rhs)
        {
            return *this + (-rhs);
        }

        inline Vector2<T>& operator-=(const Vector2<T>& rhs)
        {
            *this = *this - rhs;
            return *this;
        }

        inline Vector2<T> operator+(const Vector2<T>& rhs)
        {
            Vector2<T> result;
            result.x = x + rhs.x;
            result.y = y + rhs.y;
            return result;
        }

        inline Vector2<T>& operator+=(const Vector2<T>& rhs)
        {
            *this = *this + rhs;
            return *this;
        }

        inline Vector2<T> operator*(const T& rhs)
        {
            Vector2<T> result;
            result.x = x * rhs;
            result.y = y * rhs;
            return result;
        }

        inline Vector2<T>& operator*=(const T& rhs)
        {
            *this = *this * rhs;
            return *this;
        }

        inline Vector2<T> operator/(const T& rhs)
        {
            Vector2<T> result;
            result.x = x / rhs;
            result.y = y / rhs;
            return result;
        }

        inline Vector2<T>& operator/=(const T& rhs)
        {
            *this = *this / rhs;
            return *this;
        }

        static Vector2<T> Zero() { return Vector2<T>(); }
        static Vector2<T> One() { return Vector2<T>(static_cast<T>(1), static_cast<T>(1)); }
    };

    template <typename T>
    struct Rect
    {
        inline Rect()
        {
            x = 0;
            y = 0;
            w = 0;
            h = 0;
        }

        inline Rect(T x, T y, T w, T h)
        {
            this->x = x;
            this->y = y;
            this->w = w;
            this->h = h;
        }

        T x;
        T y;
        T w;
        T h;

        static Rect<T> Zero() { return Rect<T>(); }
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

            scale.x = 1.0f;
            scale.y = 1.0f;

            rotation = 0.0f;
        }

        Vector2f position;
        Vector2f scale;
        float rotation;

        inline Transform operator+(const Transform& rhs)
        {
            Transform result;
            result.position = position + rhs.position;
            result.rotation = rotation + rhs.rotation;
            result.scale.x = scale.x * rhs.scale.x;
            result.scale.y = scale.y * rhs.scale.y;
            return result;
        }

        inline Transform& operator+=(const Transform& rhs)
        {
            *this = *this + rhs;
            return *this;
        }
    };

    inline int Round(double in) { return (int)round(in); }
    inline int Round(float in) { return (int)round(in); }
    inline int Floor(double in) { return (int)floor(in); }
    inline int Floor(float in) { return (int)floor(in); }
    inline int Ceil(double in) { return (int)ceil(in); }
    inline int Ceil(float in) { return (int)ceil(in); }
}