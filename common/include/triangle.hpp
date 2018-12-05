#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "vertices.hpp"
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
	void render();
	void update();
};

#endif //TRIANGLE_HPP
