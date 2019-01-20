#ifndef MODEL_TRANSFORM_HPP
#define MODEL_TRANSFORM_HPP


#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <vector>

class ModelTransform
{
protected:
	glm::mat4 transform;
	unsigned transformLoc;
public:
	ModelTransform();
	ModelTransform(const ModelTransform &other);
	ModelTransform(ModelTransform &&other) noexcept;
	ModelTransform& operator=(const ModelTransform &other);
	ModelTransform& operator=(ModelTransform &&other) noexcept;
	~ModelTransform() {}
	virtual void move(const float &horizontal, const float &vertical, const float &depth);
	virtual void move(const std::vector<float> &coordinates);
	virtual void rotate(const float& speed_scale, const float &horizontal, const float &vertical, const float &turn_flat);
	virtual void rotateByPointY(const glm::vec3& t_point, const glm::vec3& t_deflection, const float& t_speed);
	virtual void scale(const float &x_scale_parameter, const float &y_scale_parameter, const float &z_scale_parameter);
	virtual void scale_whole(const float &scale_parameter);
};

#endif