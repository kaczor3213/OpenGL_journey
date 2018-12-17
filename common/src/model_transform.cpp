#include "../include/model_transform.hpp"

model_transform::model_transform()
{
	transform = glm::mat4(1.0f);
}
model_transform::model_transform(const model_transform &other)
{
	transform = other.transform;
}
model_transform::model_transform(model_transform &&other) noexcept
{
	transform = std::move(other.transform);
}
model_transform& model_transform::operator=(const model_transform &other)
{
	return *this = model_transform(other);
}
model_transform& model_transform::operator=(model_transform &&other) noexcept
{
	transform = std::move(other.transform);
	return *this;
}
void model_transform::move(const float &horizontal, const float &vertical, const float &depth)
{
	transform = glm::translate(transform, glm::vec3(horizontal, vertical, depth));
}
void model_transform::rotate(const float& speed_scale, const float &horizontal, const float &vertical, const float &turn_flat)
{
	transform = glm::rotate(transform, glm::radians(speed_scale), glm::vec3(horizontal, vertical, turn_flat));
}
void model_transform::scale(const float &x_scale_parameter, const float &y_scale_parameter, const float &z_scale_parameter)
{
	transform = glm::scale(transform, glm::vec3(x_scale_parameter, y_scale_parameter, z_scale_parameter));
}
void model_transform::scale_whole(const float &scale_parameter)
{
	transform = glm::scale(transform, glm::vec3(scale_parameter, scale_parameter, scale_parameter));
}