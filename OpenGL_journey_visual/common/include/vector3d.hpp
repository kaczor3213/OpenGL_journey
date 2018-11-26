//
// Created by Przemek on 11/18/2018.
//

#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <vector>

class vector3d
{
private:
    std::vector<double> set;
public:
    vector3d();
    vector3d(const double &x, const double &y, const double &z);
    vector3d(const vector3d &other);
    vector3d& operator=(const vector3d &other);
    vector3d(vector3d &&other) noexcept;
    vector3d& operator=(vector3d &&other) noexcept;
    double& operator[](const int &INDEX);
    ~vector3d() {}
};

#endif VECTOR3D_HPP
