#include "../include/animate.hpp"

animate::animate() {
	model = glm::mat4(1.0f);
}
animate::animate(const animate &other) {
	model = other.model;
}
animate::animate(animate &&other) noexcept {
	model = std::move(other.model);
}
animate& animate::operator=(const animate &other) {
	return *this = animate(other);
}
animate& animate::operator=(animate &&other) noexcept {
	model = std::move(other.model);
	return *this;
}

void animate::move(const float &horizontal, const float &vertical, const float &depth) {
	model = glm::translate(model, glm::vec3(vertical, horizontal, depth));
}

void animate::rotate(const float& speed_scale, const float &horizontal, const float &vertical, const float &turn_flat) {
	model = glm::rotate(model, 0.005f, glm::vec3(vertical, horizontal, turn_flat));
}

void animate::scale(const float &x_scale_parameter, const float &y_scale_parameter, const float &z_scale_parameter) {
	model = glm::scale(model, glm::vec3(x_scale_parameter, y_scale_parameter, z_scale_parameter));
}

void animate::scale_whole(const float &scale_parameter) {
	model = glm::scale(model, glm::vec3(scale_parameter, scale_parameter, 0.0f));
}