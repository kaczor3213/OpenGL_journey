#include "../include/camera.hpp"

camera::camera() {
	view = glm::mat4(1.0f);
	camPos = glm::vec3(0.0f, 0.0f, 0.0f);
	frontPos = glm::vec3(0.0f, 0.0f, -1.0f);
	upPos = glm::vec3(0.0f, 1.0f, 0.0f);
	worldUpPos = upPos;
	camYaw = -90.0f;
	camPitch = 0.0f;
	camZoom = 45.0f;
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

void camera::moveCam(const float &horizontal, const float &vertical, const float &depth) {
	view = glm::translate(view, glm::vec3(horizontal, vertical, depth));
}

void camera::rotateCam(const float& speed_scale, const float &horizontal, const float &vertical, const float &turn_flat) {
	view = glm::rotate(view, glm::radians(speed_scale), glm::vec3(horizontal, vertical, turn_flat));
}

void camera::pointCam(glm::vec3 position, glm::vec3 up, glm::vec3 front, const float &yaw, const float &pitch, const float &zoom) {
	camPos = position;
	worldUpPos = up;
	camYaw = yaw;
	camPitch = pitch;
	camZoom = zoom;
	updateCam();
}

void camera::updateCam() {
	glm::vec3 tmp;
	tmp.x = cos(glm::radians(camYaw)) * cos(glm::radians(camPitch));
	tmp.y = sin(glm::radians(camPitch));
	tmp.z = sin(glm::radians(camYaw)) * cos(glm::radians(camPitch));
	frontPos = glm::normalize(tmp);
	right = glm::normalize(glm::cross(frontPos, worldUpPos));
	upPos = glm::normalize(glm::cross(right, frontPos));
}

void camera::setViewCam() {
	view = glm::lookAt(camPos, camPos + frontPos, upPos);
}