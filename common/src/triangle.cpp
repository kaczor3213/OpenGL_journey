
#include "../include/triangle.hpp"
#include <iostream>

triangle::triangle() {
	coordinates.resize(4);
}

triangle::triangle(const triangle &other) {
	EBO = other.EBO;
	VBO = other.VBO;
	VAO = other.VAO;
	VBO_DATA = other.VBO_DATA;
	indices = other.indices;
	coordinates = other.coordinates;
}

triangle::triangle(triangle &&other) noexcept {
	EBO = std::move(other.EBO);
	VBO = std::move(other.VBO);
	VAO = std::move(other.VAO);
	VBO_DATA = std::move(other.VBO_DATA);
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
}

triangle& triangle::operator=(const triangle &other) {
	return *this = triangle(other);
}

triangle& triangle::operator=(triangle &&other) noexcept {
	EBO = std::move(other.EBO);
	VBO = std::move(other.VBO);
	VAO = std::move(other.VAO);
	VBO_DATA = std::move(other.VBO_DATA);
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
	return *this;
}

void triangle::render() {
	//indices generator
	std::cout << "dupa";
	indices = std::vector<unsigned int>{ 0,1,2 };
	data_parser();
	buff_handle();
}

void triangle::draw() {
	run();
	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

