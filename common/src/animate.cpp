#include "../include/animate.hpp"

/* PRZYDATNY FRAGMENT KODU
glm::mat4 transform = glm::mat4(1.0f);;
	transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
	transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(1.0f, -1.0f, 1.0f));

	run();

	unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

*/