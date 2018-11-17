//
// Created by Moew34 on 11/17/2018.
//
#include "../include/triangle.h"
triangle::triangle(const point &first, const point &second, const point &third)
{
    _triangle.push_back(first);
    _triangle.push_back(second);
    _triangle.push_back(third);
}
triangle::triangle(const triangle &other)
{
    _triangle = other._triangle;
}
triangle::triangle(triangle &&other) noexcept
{
    _triangle = std::move(other._triangle);
}
triangle& triangle::operator=(const triangle &other)
{
    return *this = triangle(other);
}
triangle& triangle::operator=(triangle &&other) noexcept
{
    _triangle = std::move(other._triangle);
    return *this;
}