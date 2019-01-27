#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
	Triangle();
    Triangle(const Triangle &other);
    Triangle(Triangle &&other) noexcept;
    Triangle& operator=(const Triangle &other);
    Triangle& operator=(Triangle &&other) noexcept;
	~Triangle() {}
	virtual void render();
	virtual void draw();
};

#endif
