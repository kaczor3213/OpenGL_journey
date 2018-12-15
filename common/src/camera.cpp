#include "../include/camera.hpp"

camera::camera() {
	view = glm::mat4(1.0f);
}

camera::camera(const camera &other) {
	view = other.view;
}

camera::camera(camera &&other) noexcept {
	view = std::move(other.view);
}

camera& camera::operator=(const camera &other) {
	return *this = camera(other);
}

camera& camera::operator=(camera &&other) noexcept {
	view = std::move(other.view);
	return *this;
}

void camera::move(const float &horizontal, const float &vertical, const float &depth) {
	view = glm::translate(view, glm::vec3(horizontal, vertical, depth));
}

void camera::rotate(const float& speed_scale, const float &horizontal, const float &vertical, const float &turn_flat) {
	view = glm::rotate(view, glm::radians(speed_scale), glm::vec3(horizontal, vertical, turn_flat));
}

void camera::zoom(const float &x_scale_parameter, const float &y_scale_parameter, const float &z_scale_parameter) {

}