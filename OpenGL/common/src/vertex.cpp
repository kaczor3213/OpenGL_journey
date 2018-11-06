#include "vertex.hpp"

vertex::vertex() : coordinates{ 0,0,0 } {}

vertex::vertex(const double &x, const double &y, const double &z)
{
	if (check_in_range(x) && check_in_range(y) && check_in_range(z))
	{
		coordinates.push_back(x);
		coordinates.push_back(y);
		coordinates.push_back(z);
	}
	else
	{
		exit(-1);
	}
}

vertex::vertex(const vertex &other)
{
	coordinates = other.coordinates;
}

vertex& vertex::operator=(const vertex &other)
{
	return *this = vertex(other);
}

vertex::vertex(vertex &&other) noexcept
{
	coordinates = other.coordinates;
	other.coordinates.clear();
}

vertex& vertex::operator=(vertex &&other) noexcept
{
	coordinates = other.coordinates;
	other.coordinates.clear();
	return *this;
}

bool vertex::check_in_range(const float &value)
{
	if (0.0 <= value <= 1.0) return true;
	return false;
}