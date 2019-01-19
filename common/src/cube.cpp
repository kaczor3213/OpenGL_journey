#include "../include/cube.hpp"

Cube::Cube()
{
	coordinates.resize(36);
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
	texture.textureLoc = glGetUniformLocation(shaderProgram, "ourTexture");
	glUniform1i(texture.textureLoc, 0);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

