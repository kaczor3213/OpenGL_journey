#ifndef POINT_HPP
#define POINT_HPP

#include "vertex.hpp"
#include "color.hpp"

class point : public vertex
{
private:
	color _color;
public:
	point();
	point(const vertex &VERTEX, const color &COLOR);
	point(const double &x, const double &y, const double &z, const color &COLOR);
	point(const point &other);
	point& operator=(const point &other);
	point(point &&other) noexcept;
	point& operator=(point &&other) noexcept;
	void set_color(const color &COLOR);
	color get_color();
};

point::point() : _color(COLOR_WHITE) {}

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
	coordinates = other.coordinates;
	other.coordinates.clear;
}

point& point::operator=(point &&other) noexcept
{
	std::swap(coordinates, other.coordinates);
	other.coordinates.clear;
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

#endif // !POINT_HPP
