#include "../include/point.hpp"

point::point() : _color(color(255, 255, 255, 255)) {}

point::point(const std::vector<float> &coordinate_vector, const std::vector<float> &texture_vector,  const color &COLOR)
{
	if (check_in_range(coordinate_vector[0]) &&
		check_in_range(coordinate_vector[1]) &&
		check_in_range(coordinate_vector[2]))
	{
		position[0] = coordinate_vector[0];
		position[1] = coordinate_vector[1];
		position[2] = coordinate_vector[2];
	}
	else {}
	texturecoords.x = texture_vector[0];
	texturecoords.y = texture_vector[1];
	_color = COLOR;
}

point::point(const vector3d &coordinate_vector, const vector2d &texture_vector, const color &COLOR)
{
	position = coordinate_vector;
	texturecoords = texture_vector;
	_color = COLOR;
}

point::point(const point &other)
{
	position = other.position;
	texturecoords = other.texturecoords;
}

point::point(point &&other) noexcept
{
	position = std::move(other.position);
	texturecoords = std::move(other.texturecoords);
}

point& point::operator=(const point &other)
{
	return *this = point(other);
}

point& point::operator=(point &&other) noexcept
{
	position = std::move(other.position);
	texturecoords = std::move(other.texturecoords);
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

bool point::check_in_range(const float &value)
{
	if (0.0 <= value && value <= 1.0) return true;
	return false;
}