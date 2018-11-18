//
// Created by Moew34 on 11/17/2018.
//

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "point.hpp"
#include <buffer.hpp>

class triangle : public point
{
    std::vector <point> coordinates;
public:
    triangle(const point &first, const point &second, const point &third);
    triangle(const triangle &other);
    triangle(triangle &&other) noexcept;
    triangle& operator=(const triangle &other);
    triangle& operator=(triangle &&other) noexcept;
};

#endif //TRIANGLE_H
