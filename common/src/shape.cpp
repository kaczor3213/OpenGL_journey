#include "../include/shape.hpp"
#include <iostream>

Shape::Shape(const unsigned &size) {
	indices.resize((size - 2)*3);
	coordinates.resize(size);
}

Shape::Shape(const Shape &other) {
	EBO = other.EBO;
	VBO = other.VBO;
	VAO = other.VAO;
	VBO_DATA = other.VBO_DATA;
	indices = other.indices;
	coordinates = other.coordinates;
}

Shape::Shape(Shape &&other) noexcept {
	EBO = std::move(other.EBO);
	VBO = std::move(other.VBO);
	VAO = std::move(other.VAO);
	VBO_DATA = std::move(other.VBO_DATA);
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
}

Shape& Shape::operator=(const Shape &other) {
	return *this = Shape(other);
}

Shape& Shape::operator=(Shape &&other) noexcept {
	EBO = std::move(other.EBO);
	VBO = std::move(other.VBO);
	VAO = std::move(other.VAO);
	VBO_DATA = std::move(other.VBO_DATA);
	indices = std::move(other.indices);
	coordinates = std::move(other.coordinates);
	return *this;
}

Shape::~Shape() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Shape::data_parser()
{
	VBO_DATA.resize(8 * coordinates.size());
	int k = 0;
	for (int i = 0; i < coordinates.size(); i++)
	{
		VBO_DATA[k] = coordinates[i].x;
		k++;
		VBO_DATA[k] = coordinates[i].y;
		k++;
		VBO_DATA[k] = coordinates[i].z;
		k++;
		for (int j = 0; j < 3; j++)
		{
			VBO_DATA[k] = coordinates[i].get_color().pigments[j];
			k++;
		}
		VBO_DATA[k] = coordinates[i].s;
		k++;
		VBO_DATA[k] = coordinates[i].t;
		k++;
	}

	/*
	for (int i = 0; i < coordinates.size(); i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << VBO_DATA[i * 8 + j] << "\t";
		}
		std::cout << std::endl;
	}
	*/
}

void Shape::buff_handle()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, VBO_DATA.size() * sizeof(float), &VBO_DATA[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
}

void Shape::set_shape_color(const Color &COLOR) {
	for (int i = 0; i < coordinates.size(); i++)
		coordinates[i].set_color(COLOR);
}

void Shape::set_texture(const Texture &TEXTURE) {
	texture = TEXTURE;
}

void Shape::render() {
	data_parser();
	buff_handle();
}

void Shape::draw() {
	texture.activate_textures();
	run();
	transformLoc = glGetUniformLocation(shaderProgram, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
	viewLoc = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	projectionLoc = glGetUniformLocation(shaderProgram, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
	texture.textureLoc = glGetUniformLocation(shaderProgram, "ourTexture");
	glUniform1i(texture.textureLoc, 0);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Shape::handle_input(GLFWwindow *&window) {
	process_mouse_movement(get_mouse_position(window), true);
	process_keyboard(keyboard_callback(window), 0.005f);
	process_mouse_scroll(get_scroll_position());
	get_view();
}