#include "../include/vertex.hpp"

vertex::vertex() : coordinates{ 0,0,0 } {}

vertex::vertex(const double &x, const double &y, const double &z)
{
	if (check_in_range(x) && check_in_range(y) && check_in_range(z))
	{
		coordinates = std::vector<double>{x,y,z};
		coordinates.push_back(x);
		coordinates.push_back(y);
		coordinates.push_back(z);
	}
	else
	{

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
	coordinates = std::move(other.coordinates);
}

vertex& vertex::operator=(vertex &&other) noexcept
{
	coordinates = std::move(other.coordinates);
	return *this;
}

bool vertex::check_in_range(const double &value)
{
	if (0.0 <= value && value <= 1.0) return true;
	return false;
}