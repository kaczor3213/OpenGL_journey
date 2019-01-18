#include "../include/point.hpp"

Point::Point() : color(Color(255, 255, 255, 255)) {}

Point::Point(const std::vector<float> &coordinate_vector, const Color &COLOR, const std::vector<float> &texture_vector) {
	x = coordinate_vector[0];
	y = coordinate_vector[1];
	z = coordinate_vector[2];
	color = COLOR;
	s = texture_vector[0];
	t = texture_vector[1];
}

Point::Point(const Vector3d &coordinate_vector, const Color &COLOR, const Vector2d &texture_vector) {
	 x = coordinate_vector.x;
	 y = coordinate_vector.y;
	 z = coordinate_vector.z;
	color = COLOR;
	s = texture_vector.s;
	t = texture_vector.t;
}

Point::Point(const std::vector<float> &dataSet) {
	x = dataSet[0];
	y = dataSet[1];
	z = dataSet[2];
	color = Color(255, 255, 255, 255);
	s = 0.f;
	t = 0.f;
}
Point::Point(const Point &other) {
	x = other.x;
	y = other.y;
	z = other.z;
	color = other.color;
	s = other.s;
	t = other.t;
}

Point::Point(Point &&other) noexcept {
	x = std::move(other.x);
	y = std::move(other.y);
	z = std::move(other.z);
	color = std::move(other.color);
	s = std::move(other.s);
	t = std::move(other.t);
}

Point& Point::operator=(const Point &other) {
	return *this = Point(other);
}

Point& Point::operator=(Point &&other) noexcept {
	x = std::move(other.x);
	y = std::move(other.y);
	z = std::move(other.z);
	color = std::move(other.color);
	s = std::move(other.s);
	t = std::move(other.t);
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