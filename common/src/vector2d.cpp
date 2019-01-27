#include "../include/vector2d.hpp"

Vector2d::Vector2d(const Vector2d &other) : s(other.s), t(other.t) {}

Vector2d::Vector2d(Vector2d &&other) noexcept {
	s = std::move(other.s);
	t = std::move(other.t);
}

Vector2d& Vector2d::operator=(const Vector2d &other) {
	return *this = Vector2d(other);
}

Vector2d& Vector2d::operator=(Vector2d &&other) noexcept {
	s = std::move(other.s);
	t = std::move(other.t);
	return *this;
}