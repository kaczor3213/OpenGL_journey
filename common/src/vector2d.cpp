#include "../include/vector2d.hpp"

Vector2d::Vector2d(const Vector2d &other) : q(other.q), w(other.w) {}

Vector2d::Vector2d(Vector2d &&other) noexcept {
	q = std::move(other.q);
	w = std::move(other.w);
}

Vector2d& Vector2d::operator=(const Vector2d &other) {
	return *this = Vector2d(other);
}

Vector2d& Vector2d::operator=(Vector2d &&other) noexcept {
	q = std::move(other.q);
	w = std::move(other.w);
	return *this;
}