#ifndef ANIMATE_HPP
#define ANIMATE_HPP

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "../include/color.hpp"
#include "../include/shader.hpp"

class animate : public shader
{
protected:
	glm::mat4 transform;
	unsigned int transformLoc;
public:
	animate();
	animate(const animate &other);
	animate(animate &&other) noexcept;
	animate& operator=(const animate &other);
	animate& operator=(animate &&other) noexcept;
	~animate() {}
	virtual void move(const float &horizontal, const float &vertical, const float &depth);
	virtual void rotate(const float& speed_scale, const float &horizontal, const float &vertical, const float &turn_flat);
	virtual void scale(const float &x_scale_parameter, const float &y_scale_parameter, const float &z_scale_parameter);
	virtual void scale_whole(const float &scale_parameter);
//	virtual void color_swap();
	/*
	negacja koloru
	i inne duperele
	*/
};
#endif // !ANIMATE_HPP
