#ifndef MODEL_HPP
#define MODEL_HPP

#include <glad.h>
#include <glfw3.h>
#include "shape.hpp"
#include "animate.hpp"

class model : public shape, public animate
{
public:
	model() {}
	model(const model &other);
	model(model &&other) noexcept;
	model& operator=(const model &other);
	model& operator=(model &&other) noexcept;
	virtual ~model() {}
	virtual void bindWindow(GLFWwindow &window);
	virtual void draw();
};

#endif 