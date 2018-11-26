#include "../include/vertex.hpp"


vertex::vertex(const std::vector<double> &coordinate_vector)
{
	if (check_in_range(coordinate_vector[0]) &&
		check_in_range(coordinate_vector[1]) &&
		check_in_range(coordinate_vector[2]))
	{
		position[0] = coordinate_vector[0];
		position[1] = coordinate_vector[1];
		position[2] = coordinate_vector[2];
	}
	else
	{

	}
}

vertex::vertex(const vector3d &coordinate_vector)
{
	position = coordinate_vector;
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