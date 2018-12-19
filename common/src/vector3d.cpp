#include "../include/vector3d.hpp"

Vector3d::Vector3d(const Vector3d &other) : x(other.x), y(other.y), z(other.z) {}

Vector3d& Vector3d::operator=(const Vector3d &other)
{
    return *this = Vector3d(other);
}

Vector3d::Vector3d(Vector3d &&other) noexcept
{
    x = std::move(other.x);
	y = std::move(other.y);
	z = std::move(other.z);
}

Vector3d& Vector3d::operator=(Vector3d &&other) noexcept
{
	x = std::move(other.x);
	y = std::move(other.y);
	z = std::move(other.z);
    return *this;
}