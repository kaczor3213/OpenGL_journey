#include <point.hpp>

color COLOR_RED(255, 0, 0, 0);
color COLOR_GREEN(0, 255, 0, 0);
color COLOR_BLUE(0, 0, 255, 0);
color COLOR_BLACK(0, 0, 0, 0);
color COLOR_WHITE(255, 255, 255, 0);

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
	other.coordinates.clear();
}

point& point::operator=(point &&other) noexcept
{
	std::swap(coordinates, other.coordinates);
	other.coordinates.clear();
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
