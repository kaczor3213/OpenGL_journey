#ifndef ANIMATE_HPP
#define ANIMATE_HPP

#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "../include/color.hpp"
#include "../include/shader.hpp"

class animate : public shader
{
	glm::mat4 transform = glm::mat4(1.0f);
public:
	animate();
	animate(const animate &other);
	animate(animate &&other) noexcept;
	animate& operator=(const animate &other);
	animate& operator=(animate &&other) noexcept;
	~animate();
	virtual void move();
	virtual void rotate();
	virtual void scale();
	virtual void color_swap();
	/*
	negacja koloru
	i inne duperele
	*/
};
#endif // !ANIMATE_HPP
