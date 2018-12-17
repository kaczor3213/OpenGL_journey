#include "../include/vector2d.hpp"

vector2d::vector2d(const vector2d &other) : x(other.x), y(other.y) {}

vector2d::vector2d(vector2d &&other) noexcept {
	x = std::move(other.x);
	y = std::move(other.y);
}

vector2d& vector2d::operator=(const vector2d &other) {
	return *this = vector2d(other);
}

vector2d& vector2d::operator=(vector2d &&other) noexcept {
	x = std::move(other.x);
	y = std::move(other.y);
	return *this;
}