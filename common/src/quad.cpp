#include "../include/quad.hpp"

quad::quad() {
	coordinates.resize(4);
}

quad::quad(const quad &other) {
	EBO = other.EBO;
	VBO = other.VBO;
	VAO = other.VAO;
	VBO_DATA = other.VBO_DATA;
	indices = other.indices;
	coordinates = other.coordinates;
}

quad::quad(quad &&other) noexcept {
	EBO = std::move(other.EBO);
	VBO = std::move(other.VBO);
	VAO = std::move(other.VAO);
	VBO_DATA = std::move(other.VBO_DATA);
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
}

quad& quad::operator=(const quad &other) {
	return *this = quad(other);
}

quad& quad::operator=(quad &&other) noexcept {
	EBO = std::move(other.EBO);
	VBO = std::move(other.VBO);
	VAO = std::move(other.VAO);
	VBO_DATA = std::move(other.VBO_DATA);
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
	return *this;
}

void quad::render() {
	indices = std::vector<unsigned int>{ 0,1,2,0,2,3 };
	data_parser();
	buff_handle();
}

