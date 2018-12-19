#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <algorithm>

class Vector2d
{
public:
	float q;
	float w;
	Vector2d() : q(0), w(0) {}
	Vector2d(const float &Q, const float &W) : q(Q), w(W) {}
	Vector2d(const Vector2d &other);
	Vector2d& operator=(const Vector2d &other);
	Vector2d(Vector2d &&other) noexcept;
	Vector2d& operator=(Vector2d &&other) noexcept;
	~Vector2d() {}
};

#endif
