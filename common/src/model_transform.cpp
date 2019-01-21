#include "../include/model_transform.hpp"
#include <iostream>
#include <cmath>
#include <ctime>

ModelTransform::ModelTransform()
{
	sum = 0;
	vCurrentPosition = glm::vec3(0.0f);
	m_position = glm::mat4(1.0f);
	m_rotation = glm::mat4(1.0f);
}

ModelTransform::ModelTransform(const ModelTransform &other)
{
	transform = other.transform;
}

ModelTransform::ModelTransform(ModelTransform &&other) noexcept
{
	transform = std::move(other.transform);
}

ModelTransform& ModelTransform::operator=(const ModelTransform &other)
{
	return *this = ModelTransform(other);
}

ModelTransform& ModelTransform::operator=(ModelTransform &&other) noexcept
{
	transform = std::move(other.transform);
	return *this;
}

void ModelTransform::move(const float &horizontal, const float &vertical, const float &depth)
{
	vMove = glm::vec3(horizontal, vertical, depth);
	vCurrentPosition += vMove;
	m_position = glm::translate(m_position, vMove);
	std::cout << vCurrentPosition.x << "\t" << vCurrentPosition.y << "\t" << vCurrentPosition.z << "\n";
}

void ModelTransform::pitch(const float& angle) {
	m_rotation = glm::rotate(m_rotation, angle, X_AXIS);
}

void ModelTransform::yaw(const float& angle) {
	m_rotation = glm::rotate(m_rotation, angle, Y_AXIS);
}

void ModelTransform::roll(const float& angle) {
	m_rotation = glm::rotate(m_rotation, angle, Z_AXIS);
}

void ModelTransform::moveByPoint(const glm::vec3& t_point, float angle) {
	sum += angle;
	float radius = glm::length(t_point - vCurrentPosition);
	glm::vec3 newPosition(t_point.x + cos(sum +1.57) * radius, t_point.y + sin(sum + 1.57) * radius,t_point.z);
	m_position = glm::translate(m_position, newPosition - vCurrentPosition);
	vCurrentPosition = newPosition;
}

void ModelTransform::transformation() {
	transform = glm::mat4(1.0f);
	transform = m_position * m_rotation;
}

void ModelTransform::scale(const float &x_scale_parameter, const float &y_scale_parameter, const float &z_scale_parameter) {
	transform = glm::scale(transform, glm::vec3(x_scale_parameter, y_scale_parameter, z_scale_parameter));
}
void ModelTransform::scale_whole(const float &scale_parameter) {
	transform = glm::scale(transform, glm::vec3(scale_parameter, scale_parameter, scale_parameter));
}