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

void camera::move(const float &horizontal, const float &vertical, const float &depth) {
	view = glm::translate(view, glm::vec3(horizontal, vertical, depth));
}

void camera::rotate(const float& speed_scale, const float &horizontal, const float &vertical, const float &turn_flat) {
	view = glm::rotate(view, glm::radians(speed_scale), glm::vec3(horizontal, vertical, turn_flat));
}

void camera::pointCam(glm::vec3 position, glm::vec3 up, glm::vec3 front, float yaw, float pitch, float zoom)
{
	camPos = position;
	worldUpPos = up;
	camYaw = yaw;
	camPitch = pitch;
	camZoom = zoom;
	updateCam();
}

void camera::updateCam()
{
	glm::vec3 tmp;
	tmp.x = cos(glm::radians(camYaw)) * cos(glm::radians(camPitch));
	tmp.y = sin(glm::radians(camPitch));
	tmp.z = sin(glm::radians(camYaw)) * cos(glm::radians(camPitch));
	frontPos = glm::normalize(tmp);
	right = glm::normalize(glm::cross(frontPos, worldUpPos));
	upPos = glm::normalize(glm::cross(right, frontPos));
}

void camera::setView()
{
	view = glm::lookAt(camPos, camPos + frontPos, upPos);
}

void camera::procKeys(camMov dir, float inTime)
{
	if (dir == FORWARD) camPos += frontPos * 2.5f * inTime;
	if (dir == BACKWARD) camPos -= frontPos * 2.5f * inTime;
	if (dir == RIGHT) camPos += right * 2.5f * inTime;
	if (dir == LEFT) camPos -= right * 2.5f * inTime;
}

void camera::procMouseMov(float xoffs, float yoffs, GLboolean constrain)
{
	camYaw += xoffs * 0.1f;
	camPitch = yoffs * 0.1f;
	if (constrain)
	{
		if (camPitch > 89.0f) camPitch = 89.0f;
		if (camPitch < -89.0f) camPitch = -89.0f;
	}
	updateCam();
}

void camera::procMouseZoom(float yoffs)
{
	if (camZoom >= 1.0f && camZoom <= 45.0f) camZoom -= yoffs;
	if (camZoom <= 1.0f) camZoom = 1.0f;
	if (camZoom >= 45.0f) camZoom = 45.0f;
}