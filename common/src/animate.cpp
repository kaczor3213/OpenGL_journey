#include "../include/animate.hpp"

animate::animate() {
	transform = glm::mat4(1.0f);
}
animate::animate(const animate &other) {
	transform = other.transform;
}
animate::animate(animate &&other) noexcept {
	transform = std::move(other.transform);
}
animate& animate::operator=(const animate &other) {
	return *this = animate(other);
}
animate& animate::operator=(animate &&other) noexcept {
	transform = std::move(other.transform);
	return *this;
}

void animate::move(const float &horizontal, const float &vertical, const float &depth) {
	transform = glm::translate(transform, glm::vec3(vertical, horizontal, depth));
}

void animate::rotate(const float &horizontal, const float &vertical, const float &turn_flat) {
	transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(vertical, horizontal, turn_flat));
}

void animate::scale(const float &x_scale_parameter, const float &y_scale_parameter, const float &z_scale_parameter) {
	transform = glm::scale(transform, glm::vec3(x_scale_parameter, y_scale_parameter, z_scale_parameter));
}

void animate::scale_whole(const float &scale_parameter) {
	transform = glm::scale(transform, glm::vec3(scale_parameter, scale_parameter, 0.0f));
}