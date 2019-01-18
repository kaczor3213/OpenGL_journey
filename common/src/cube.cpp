#include "../include/cube.hpp"
#include <iostream>

Cube::Cube()
{
	coordinates.resize(36);
}

void Cube::generate()
{
}

void Cube::render_cube()
{
	render();
	buff_handle();
}

void Cube::draw()
{
	run();
	transformLoc = glGetUniformLocation(shaderProgram, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
	viewLoc = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	projectionLoc = glGetUniformLocation(shaderProgram, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}