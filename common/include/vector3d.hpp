#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <vector>

class Vector3d
{
public:
	float x, y, z;
    Vector3d() : x(0), y(0), z(0) {}
    Vector3d(const float &X, const float &Y, const float &Z) : x(X), y(Y), z(Z) {}
    Vector3d(const Vector3d &other);
    Vector3d& operator=(const Vector3d &other);
    Vector3d(Vector3d &&other) noexcept;
    Vector3d& operator=(Vector3d &&other) noexcept;
    ~Vector3d() {}
};

#endif
