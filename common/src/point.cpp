#include "../include/point.hpp"

point::point() : _color(color(255, 255, 255, 0)) {}

point::point(const vertex &VERTEX, const color &COLOR)
{
	coordinates = VERTEX.coordinates;
	_color = COLOR;
}

point::point(const double &x, const double &y, const double &z, const color &COLOR)
{
	coordinates.push_back(x);
	coordinates.push_back(y);
	coordinates.push_back(z);
	_color = COLOR;
}
point::point(const point &other)
{
	coordinates = other.coordinates;
}

point& point::operator=(const point &other)
{
	return *this = point(other);
}

point::point(point &&other) noexcept
{
	coordinates = std::move(other.coordinates);
}

point& point::operator=(point &&other) noexcept
{
	coordinates = std::move(other.coordinates);
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
