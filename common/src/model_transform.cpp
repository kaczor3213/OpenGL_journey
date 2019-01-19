#include "../include/model_transform.hpp"

ModelTransform::ModelTransform()
{
	transform = glm::mat4(1.0f);
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
	transform = glm::translate(transform, glm::vec3(horizontal, vertical, depth));
}
void ModelTransform::move(const std::vector<float> &coordinates)
{
	transform = glm::translate(transform, glm::vec3(coordinates[0], coordinates[1], coordinates[2]));
}
void ModelTransform::rotate(const float& speed_scale, const float &horizontal, const float &vertical, const float &turn_flat)
{
	transform = glm::rotate(transform, glm::radians(speed_scale), glm::vec3(horizontal, vertical, turn_flat));
}
void ModelTransform::scale(const float &x_scale_parameter, const float &y_scale_parameter, const float &z_scale_parameter)
{
	transform = glm::scale(transform, glm::vec3(x_scale_parameter, y_scale_parameter, z_scale_parameter));
}
void ModelTransform::scale_whole(const float &scale_parameter)
{
	transform = glm::scale(transform, glm::vec3(scale_parameter, scale_parameter, scale_parameter));
}