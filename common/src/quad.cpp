#include "../include/quad.hpp"

Quad::Quad() {
	coordinates.resize(4);
}

Quad::Quad(const Quad &other) {
	EBO = other.EBO;
	VBO = other.VBO;
	VAO = other.VAO;
	VBO_DATA = other.VBO_DATA;
	indices = other.indices;
	coordinates = other.coordinates;
}

Quad::Quad(Quad &&other) noexcept {
	EBO = std::move(other.EBO);
	VBO = std::move(other.VBO);
	VAO = std::move(other.VAO);
	VBO_DATA = std::move(other.VBO_DATA);
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
}

Quad& Quad::operator=(const Quad &other) {
	return *this = Quad(other);
}

Quad& Quad::operator=(Quad &&other) noexcept {
	EBO = std::move(other.EBO);
	VBO = std::move(other.VBO);
	VAO = std::move(other.VAO);
	VBO_DATA = std::move(other.VBO_DATA);
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
	return *this;
}

void Quad::render() {
	indices = std::vector<unsigned int>{ 0,1,2,0,2,3 };
	data_parser();
	buff_handle();
}

