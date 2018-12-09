#include "../include/worldspace.hpp"

worldspace::worldspace()
{
	view = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);
	viewLoc = 0;
	projectionLoc = 0;
}
worldspace::worldspace(const worldspace &other)
{
	view = other.view;
	projection = other.projection;
}
worldspace::worldspace(worldspace &&other) noexcept
{
	view = std::move(other.view);
	projection = std::move(other.projection);
}
worldspace& worldspace::operator=(const worldspace &other)
{
	return *this = worldspace(other);
}
worldspace& worldspace::operator=(worldspace &&other) noexcept
{
	view = std::move(other.view);
	projection = std::move(other.projection);
	return *this;
}
void worldspace::set_view(const float &horizontal, const float &vertical, const float &depth)
{
	view = glm::translate(view, glm::vec3(horizontal, vertical, depth));
}
void worldspace::set_projection(const float &angle, const float &scr_width, const float &scr_height)
{
	projection = glm::perspective(glm::radians(angle), scr_width / scr_height, 0.1f, 100.0f);
}
void worldspace::draw_world()
{
	run();
	draw();
	viewLoc = glGetUniformLocation(shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
	projectionLoc = glGetUniformLocation(shaderProgram, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}