#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <algorithm>

class Vector2d
{
public:
	float s;
	float t;
	Vector2d() : s(0), t(0) {}
	Vector2d(const float &S, const float &T) : s(S), t(T) {}
	Vector2d(const Vector2d &other);
	Vector2d& operator=(const Vector2d &other);
	Vector2d(Vector2d &&other) noexcept;
	Vector2d& operator=(Vector2d &&other) noexcept;
	~Vector2d() {}
};

#endif
