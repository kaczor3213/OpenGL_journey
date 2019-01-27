#include "../include/camera.hpp"
#include <iostream>

Camera::Camera() {
	projection = glm::mat4(1.0f);
	view = glm::mat4(1.0f);
	Position = glm::vec3(0.0f, 0.0f, 0.0f);
	Front = glm::vec3(0.0f, 0.0f, -1.0f);
	Up = glm::vec3(0.0f, 1.0f, 0.0f);
	WorldUp = Up;

	Yaw = YAW;
	Pitch = PITCH;
	Zoom = ZOOM;

	MovementSpeed = SPEED;
	MouseSensitivity = SENSITIVITY;
}

Camera::Camera(const Camera &other) {
	view = other.view;
}

Camera::Camera(Camera &&other) noexcept {
	view = std::move(other.view);
}

Camera& Camera::operator=(const Camera &other) {
	return *this = Camera(other);
}

Camera& Camera::operator=(Camera &&other) noexcept {
	view = std::move(other.view);
	return *this;
}

void Camera::process_keyboard(CameraMovement direction, const float &deltaTime) {
	float velocity = MovementSpeed * deltaTime;
	if (direction == FORWARD)
		Position += Front * velocity;
	if (direction == BACKWARD)
		Position -= Front * velocity;
	if (direction == LEFT)
		Position -= Right * velocity;
	if (direction == RIGHT)
		Position += Right * velocity;
}

void Camera::process_mouse_movement(const float &xoffset, const float &yoffset, bool constrainPitch) {
	Yaw += xoffset * MouseSensitivity;
	Pitch += yoffset * MouseSensitivity;
	if (true)
	{
		if (Pitch > 89.0f)
			Pitch = 89.0f;
		if (Pitch < -89.0f)
			Pitch = -89.0f;
	}
	std:
	update();
}

void Camera::process_mouse_movement(const Vector2d &offset, bool constrainPitch) {
	Yaw += offset.s * MouseSensitivity;
	Pitch += offset.t * MouseSensitivity;
	if (true)
	{
		if (Pitch > 89.0f)
			Pitch = 89.0f;
		if (Pitch < -89.0f)
			Pitch = -89.0f;
	}
	update();
}

void Camera::process_mouse_scroll(double yoffset) {
	if (Zoom >= 1.0f && Zoom <= 45.0f)
		Zoom -= yoffset;
	if (Zoom <= 1.0f)
		Zoom = 1.0f;
	if (Zoom >= 45.0f)
		Zoom = 45.0f;
}

void Camera::camera_move(const float &horizontal, const float &vertical, const float &depth) {
	view = glm::translate(view, glm::vec3(horizontal, vertical, depth));
}

void Camera::camera_rotate(const float& speed_scale, const float &horizontal, const float &vertical, const float &turn_flat) {
	view = glm::rotate(view, glm::radians(speed_scale), glm::vec3(horizontal, vertical, turn_flat));
}

void Camera::camera_place(glm::vec3 position, glm::vec3 up, glm::vec3 front, const float &yaw, const float &pitch, const float &zoom) {
	Position = position;
	WorldUp = up;
	Yaw = yaw;
	Pitch = pitch;
	Zoom = zoom;
}

void Camera::update() {
	glm::vec3 tmp;
	tmp.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	tmp.y = sin(glm::radians(Pitch));
	tmp.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	Front = glm::normalize(tmp);
	Right = glm::normalize(glm::cross(Front, WorldUp));
	Up = glm::normalize(glm::cross(Right, Front));
}

void Camera::get_view() {
	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 600;
	view = glm::lookAt(Position, Position + Front, Up);
	projection = glm::perspective(glm::radians(Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

}