#include "../include/quad.hpp"
<<<<<<< HEAD
///prepare for proper indices arrays
quad::quad() {
	indices = std::vector<unsigned>{ 0,1,2,0,2,3};
=======

quad::quad() {
>>>>>>> dev
	coordinates.resize(4);
}

quad::quad(const quad &other) {
<<<<<<< HEAD
=======
	EBO = other.EBO;
	VBO = other.VBO;
	VAO = other.VAO;
	VBO_DATA = other.VBO_DATA;
>>>>>>> dev
	indices = other.indices;
	coordinates = other.coordinates;
}

quad::quad(quad &&other) noexcept {
<<<<<<< HEAD
=======
	EBO = std::move(other.EBO);
	VBO = std::move(other.VBO);
	VAO = std::move(other.VAO);
	VBO_DATA = std::move(other.VBO_DATA);
>>>>>>> dev
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
}

quad& quad::operator=(const quad &other) {
	return *this = quad(other);
}

quad& quad::operator=(quad &&other) noexcept {
<<<<<<< HEAD
=======
	EBO = std::move(other.EBO);
	VBO = std::move(other.VBO);
	VAO = std::move(other.VAO);
	VBO_DATA = std::move(other.VBO_DATA);
>>>>>>> dev
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
	return *this;
}

<<<<<<< HEAD
=======
void quad::render() {
	indices = std::vector<unsigned int>{ 0,1,2,0,2,3 };
	data_parser();
	buff_handle();
}

>>>>>>> dev
