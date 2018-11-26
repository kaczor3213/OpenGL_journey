#include "../include/point.hpp"

point::point() : _color(color(255, 255, 255, 0)) {}

point::point(const vertex &VERTEX, const color &COLOR)
{
	position = VERTEX.position;
	_color = COLOR;
}

point::point(const std::vector<double> &coordinate_vector, const color &COLOR)
{
	///to fix
	position[0] = coordinate_vector[0];
	position[1] = coordinate_vector[1];
	position[2] = coordinate_vector[2];
	_color = COLOR;
}

point::point(const vector3d &coordinate_vector, const color &COLOR)
{
	position = coordinate_vector;
	_color = COLOR;
}

point::point(const point &other)
{
	position = other.position;
}

point& point::operator=(const point &other)
{
	return *this = point(other);
}

point::point(point &&other) noexcept
{
	position = other.position;
}

point& point::operator=(point &&other) noexcept
{
	position =other.position;
	return *this;
}

void point::set_color(const color &COLOR)
{
	_color = COLOR;
}

color point::get_color()
{
	return _color;
}
