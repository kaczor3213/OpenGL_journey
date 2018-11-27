//
// Created by Przemek on 11/18/2018.
//
#include "../include/vector3d.hpp"

vector3d::vector3d()
{
    set.resize(3);
}

vector3d::vector3d(const float &x, const float &y, const float &z)
{
    set.push_back(x);
    set.push_back(y);
    set.push_back(z);
}

vector3d::vector3d(const vector3d &other) : set(other.set) {}

vector3d& vector3d::operator=(const vector3d &other)
{
    return *this = vector3d(other);
}

vector3d::vector3d(vector3d &&other) noexcept
{
    set = std::move(other.set);
}

vector3d& vector3d::operator=(vector3d &&other) noexcept
{
    set = std::move(other.set);
    return *this;
}

float& vector3d::operator[](const int &index)
{
    return set[index];
}

float vector3d::operator[](const int &index) const
{
	return set[index];
}