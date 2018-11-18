#include "../include/vertex.hpp"

vertex::vertex() : position{0} {}

vertex::vertex(const double &POSITION)
{
	if (check_in_range(POSITION))
	{
		position = POSITION;
	}
	else
	{

	}
}

vertex::vertex(const vertex &other)
{
	position = other.position;
}

vertex& vertex::operator=(const vertex &other)
{
	return *this = vertex(other);
}

vertex::vertex(vertex &&other) noexcept
{
	position = other.position;
}

vertex& vertex::operator=(vertex &&other) noexcept
{
	position = other.position;
	return *this;
}

bool vertex::check_in_range(const double &value)
{
	if (0.0 <= value && value <= 1.0) return true;
	return false;
}