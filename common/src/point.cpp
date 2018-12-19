#include "../include/point.hpp"

Point::Point() : color(Color(255, 255, 255, 255)) {}

Point::Point(const std::vector<float> &coordinate_vector, const Color &COLOR, const std::vector<float> &texture_vector) {
	if (check_in_range(coordinate_vector[0]) &&
		check_in_range(coordinate_vector[1]) &&
		check_in_range(coordinate_vector[2]))
	{
		x = coordinate_vector[0];
		y = coordinate_vector[1];
		z = coordinate_vector[2];
	}
	else {}
	color = COLOR;
	q = texture_vector[0];
	w = texture_vector[1];
}

Point::Point(const Vector3d &coordinate_vector, const Color &COLOR, const Vector2d &texture_vector) {
	 x = coordinate_vector.x;
	 y = coordinate_vector.y;
	 z = coordinate_vector.z;
	color = COLOR;
	q = texture_vector.q;
	w = texture_vector.w;
}

Point::Point(const Point &other) {
	x = other.x;
	y = other.y;
	z = other.z;
	color = other.color;
	q =  other.q;
	w =  other.w;
}

Point::Point(Point &&other) noexcept {
	x = std::move(other.x);
	y = std::move(other.y);
	z = std::move(other.z);
	color = std::move(other.color);
	q = std::move(other.q);
	w = std::move(other.w);
}

Point& Point::operator=(const Point &other) {
	return *this = Point(other);
}

Point& Point::operator=(Point &&other) noexcept {
	x = std::move(other.x);
	y = std::move(other.y);
	z = std::move(other.z);
	color = std::move(other.color);
	q = std::move(other.q);
	w = std::move(other.w);
	return *this;
}

void Point::set_coordinates(const float &X, const float &Y, const float &Z) {
	x = X;
	y = Y;
	z = Z;
}

void Point::set_color(const Color &COLOR) {
	color = COLOR;
}

Color Point::get_color() {
	return color;
}

bool Point::check_in_range(const float &value) {
	if (0.0 <= value && value <= 1.0) return true;
	return false;
}