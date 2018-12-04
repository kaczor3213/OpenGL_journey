#include "../include/polygon.hpp"

polygon::polygon(const unsigned &size) {
	coordinates.resize(size);
}

polygon::polygon(const polygon &other) {
	indices = other.indices;
	coordinates = other.coordinates;
}

polygon::polygon(polygon &&other) noexcept {
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
}

polygon& polygon::operator=(const polygon &other) {
	return *this = polygon(other);
}

polygon& polygon::operator=(polygon &&other) noexcept {
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
	return *this;
}

void polygon::resize(const unsigned &size) {
	coordinates.resize(size);
}