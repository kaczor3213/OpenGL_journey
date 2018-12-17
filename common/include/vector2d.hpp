#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <algorithm>

class vector2d
{
public:
	float x;
	float y;
	vector2d() : x(0), y(0) {}
	vector2d(const float &X, const float &Y) : x(X), y(Y) {}
	vector2d(const vector2d &other);
	vector2d& operator=(const vector2d &other);
	vector2d(vector2d &&other) noexcept;
	vector2d& operator=(vector2d &&other) noexcept;
	~vector2d() {}
};

#endif
