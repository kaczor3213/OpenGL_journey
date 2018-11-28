#include "../include/quad.hpp"

quad::quad() {
	//indices = std::vector<double>{ 0,1,2,3};
	coordinates.resize(4);
}

quad::quad(const quad &other) {
	indices = other.indices;
	coordinates = other.coordinates;
}

quad::quad(quad &&other) noexcept {
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
}

quad& quad::operator=(const quad &other) {
	return *this = quad(other);
}

quad& quad::operator=(quad &&other) noexcept {
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
	return *this;
}
