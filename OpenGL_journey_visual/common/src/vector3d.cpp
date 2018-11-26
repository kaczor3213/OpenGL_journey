//
// Created by Przemek on 11/18/2018.
//
#include "../include/vector3d.hpp"

vector3d::vector3d()
{
    set.resize(3);
}

vector3d::vector3d(const double &x, const double &y, const double &z)
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

double& vector3d::operator[](const int &index)
{
       return set[index];
}