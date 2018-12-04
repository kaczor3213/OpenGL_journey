//
// Created by Moew34 on 11/17/2018.
//

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "vertices.hpp"
#include "shape.hpp"
#include "shader.hpp"

class triangle : public shape
{
public:
	triangle();
    triangle(const triangle &other);
    triangle(triangle &&other) noexcept;
    triangle& operator=(const triangle &other);
    triangle& operator=(triangle &&other) noexcept;
	~triangle() {}
};

#endif //TRIANGLE_HPP
