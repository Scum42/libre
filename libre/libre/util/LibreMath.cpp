#include "LibreMath.h"

#include <cmath>

using namespace libre;

// ========================================================
// Operator overoads: Vector2<T>
// ========================================================

template <typename T>
Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
    Vector2<T> result;
    result.x = lhs.x + rhs.x;
    result.y = lhs.y + rhs.y;
    return result;
}

template <typename T>
Vector2<T>& operator+=(Vector2<T>& lhs, Vector2<T> rhs)
{
    lhs = lhs + rhs;
    return lhs;
}

template <typename T>
Vector2<T> operator*(const Vector2<T>& lhs, T rhs)
{
    Vector2<T> result;
    result.x = lhs.x * rhs;
    result.y = lhs.y * rhs;
    return result;
}

template <typename T>
Vector2<T>& operator*=(Vector2<T>& lhs, T rhs)
{
    lhs = lhs * rhs;
    return lhs;
}

template <typename T>
Vector2<T> operator/(const Vector2<T>& lhs, T rhs)
{
    Vector2<T> result;
    result.x = x / rhs;
    result.y = y / rhs;
    return result;
}

template <typename T>
Vector2<T>& operator/=(Vector2<T>& lhs, T rhs)
{
    lhs = lhs / rhs;
    return lhs;
}

// ========================================================
// Operator overoads: Transform
// ========================================================

Transform operator+(const Transform& lhs, const Transform& rhs)
{
    Transform result;
    result.position = lhs.position + rhs.position;
    result.rotation = lhs.rotation + rhs.rotation;
    result.scale.x = lhs.scale.x * rhs.scale.x;
    result.scale.y = lhs.scale.y * rhs.scale.y;
    return result;
}