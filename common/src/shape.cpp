#include "../include/shape.hpp"

shape::shape(const unsigned &size) {
	indices.resize((size - 2)*3);
	coordinates.resize(size);
}

shape::shape(const shape &other) {
	EBO = other.EBO;
	VBO = other.VBO;
	VAO = other.VAO;
	VBO_DATA = other.VBO_DATA;
	indices = other.indices;
	coordinates = other.coordinates;
}

shape::shape(shape &&other) noexcept {
	EBO = std::move(other.EBO);
	VBO = std::move(other.VBO);
	VAO = std::move(other.VAO);
	VBO_DATA = std::move(other.VBO_DATA);
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
}

shape& shape::operator=(const shape &other) {
	return *this = shape(other);
}

shape& shape::operator=(shape &&other) noexcept {
	EBO = std::move(other.EBO);
	VBO = std::move(other.VBO);
	VAO = std::move(other.VAO);
	VBO_DATA = std::move(other.VBO_DATA);
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
	return *this;
}

shape::~shape() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void shape::data_parser()
{
	VBO_DATA.resize(7 * coordinates.size());
	int k = 0;
	for (int i = 0; i < coordinates.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			VBO_DATA[k] = coordinates[i].position[j];
			k++;
		}
		for (int j = 0; j < 4; j++)
		{
			VBO_DATA[k] = coordinates[i].get_color().pigments[j];
			k++;
		}
	}
}

void shape::buff_handle()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, VBO_DATA.size() * sizeof(float), &VBO_DATA[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void shape::render() {
	data_parser();
	buff_handle();
}
/*
void shape::draw() {
	run();
	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
}
*/
void shape::draw() {
	run();
	modelLoc = glGetUniformLocation(shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
}


