#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class triangle : public shape
{
public:
	triangle();
    triangle(const triangle &other);
    triangle(triangle &&other) noexcept;
    triangle& operator=(const triangle &other);
    triangle& operator=(triangle &&other) noexcept;
	~triangle() {}
	virtual void render();
	virtual void draw();
};

#endif //TRIANGLE_HPP
