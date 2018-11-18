//
// Created by Moew34 on 11/17/2018.
//
#include "triangle.hpp"

triangle::triangle(const point &first, const point &second, const point &third)
{
    coordinates.push_back(first);
    coordinates.push_back(second);
    coordinates.push_back(third);
}
triangle::triangle(const triangle &other)
{
    coordinates = other.coordinates;
}
triangle::triangle(triangle &&other) noexcept
{
    coordinates = std::move(other.coordinates);
}
triangle& triangle::operator=(const triangle &other)
{
    return *this = triangle(other);
}
triangle& triangle::operator=(triangle &&other) noexcept
{
    coordinates = std::move(other.coordinates);
    return *this;
}