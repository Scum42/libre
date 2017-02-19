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

	typedef Point<int> IPoint;
	typedef Point<float> FPoint;
	typedef Point<double> DPoint;

	typedef Rect<int> IRect;
	typedef Rect<float> FRect;
	typedef Rect<double> DRect;
}

#endif