#include "../include/model_transform.hpp"
#include <iostream>

ModelTransform::ModelTransform()
{
	sum = phaseX = phaseY = phaseZ = 0;
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
	calc_phase_by_x();
	calc_phase_by_y();
	calc_phase_by_z();
	std::cout << vCurrentPosition.x << "\t" << vCurrentPosition.y << "\t" << vCurrentPosition.z << "\n";
}

void ModelTransform::calc_phase_by_x()
{
	phaseX = asin(vCurrentPosition.y / sqrt(vCurrentPosition.z*vCurrentPosition.z + vCurrentPosition.y*vCurrentPosition.y));
	if (vCurrentPosition.z < 0 && vCurrentPosition.y < 0) phaseX -= M_PI / 2;
	if (vCurrentPosition.z < 0 && vCurrentPosition.y > 0) phaseX += M_PI / 2;
	if (vCurrentPosition.z < 0 && vCurrentPosition.y == 0) phaseX = M_PI;
}

void ModelTransform::calc_phase_by_y()
{
	phaseY = asin(vCurrentPosition.z / sqrt(vCurrentPosition.x*vCurrentPosition.x + vCurrentPosition.z*vCurrentPosition.z));
	if (vCurrentPosition.x < 0 && vCurrentPosition.z < 0) phaseY -= M_PI / 2;
	if (vCurrentPosition.x < 0 && vCurrentPosition.z > 0) phaseY += M_PI / 2;
	if (vCurrentPosition.x < 0 && vCurrentPosition.z == 0) phaseY = M_PI;
}

void ModelTransform::calc_phase_by_z()
{
	phaseZ = asin(vCurrentPosition.y / sqrt(vCurrentPosition.x*vCurrentPosition.x + vCurrentPosition.y*vCurrentPosition.y));
	if (vCurrentPosition.x < 0 && vCurrentPosition.y < 0) phaseZ -= M_PI / 2;
	if (vCurrentPosition.x < 0 && vCurrentPosition.y > 0) phaseZ += M_PI / 2;
	if (vCurrentPosition.x < 0 && vCurrentPosition.y == 0) phaseZ = M_PI;
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

void ModelTransform::move_by_x(const glm::vec3& t_point, float angle) {
	sum += angle;
	float radius = glm::length(t_point - vCurrentPosition);
	glm::vec3 newPosition(t_point.x , t_point.y + sin(sum + phaseX)* radius, t_point.z + cos(sum + phaseX) * radius);
	m_position = glm::translate(m_position, newPosition - vCurrentPosition);
	vCurrentPosition = newPosition;
}

void ModelTransform::move_by_y(const glm::vec3& t_point, float angle) {
	sum += angle;
	float radius = glm::length(t_point - vCurrentPosition);
	glm::vec3 newPosition(t_point.x + cos(sum + phaseY) * radius, t_point.y, t_point.z + sin(sum + phaseY) * radius);
	m_position = glm::translate(m_position, newPosition - vCurrentPosition);
	vCurrentPosition = newPosition;
}

void ModelTransform::move_by_z(const glm::vec3& t_point, float angle) {
	sum += angle;
	float radius = glm::length(t_point - vCurrentPosition);
	glm::vec3 newPosition(t_point.x + cos(sum + phaseZ) * radius, t_point.y + sin(sum + phaseZ) * radius,t_point.z);
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