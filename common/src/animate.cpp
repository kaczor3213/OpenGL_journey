#include "../include/animate.hpp"

animate::animate(const animate &other)
{
	transform = other.transform;
}
animate::animate(animate &&other) noexcept
{
	transform = std::move(other.transform);
}
animate& animate::operator=(const animate &other)
{
	return *this = animate(other);
}
animate& animate::operator=(animate &&other) noexcept
{
	transform = std::move(other.transform);
	return *this;
}
void animate::move()
{
	transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
}
void animate::rotate()
{
	transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(1.0f, -1.0f, 1.0f));
}
void animate::scale()
{
	transform = glm::scale(transform, glm::vec3(0.5, 0.5, 0.5));
}
/* PRZYDATNY FRAGMENT KODU
glm::mat4 transform = glm::mat4(1.0f);;
	transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
	transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(1.0f, -1.0f, 1.0f));

	run();

	unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

*/