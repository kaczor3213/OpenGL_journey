#ifndef MODEL_TRANSFORM_HPP
#define MODEL_TRANSFORM_HPP


#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class model_transform
{
protected:
	glm::mat4 transform;
	unsigned transformLoc;
public:
	model_transform();
	model_transform(const model_transform &other);
	model_transform(model_transform &&other) noexcept;
	model_transform& operator=(const model_transform &other);
	model_transform& operator=(model_transform &&other) noexcept;
	~model_transform() {}
	virtual void move(const float &horizontal, const float &vertical, const float &depth);
	virtual void rotate(const float& speed_scale, const float &horizontal, const float &vertical, const float &turn_flat);
	virtual void scale(const float &x_scale_parameter, const float &y_scale_parameter, const float &z_scale_parameter);
	virtual void scale_whole(const float &scale_parameter);
};

#endif