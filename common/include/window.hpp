#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <glad.h>
#include <glfw3.h>
#include <string>
#include "camera.hpp"

#define SCR_WIDTH  800
#define SCR_HEIGHT 600

class window
{
private:
	std::string title;
	GLFWwindow *_window;

public:
	window();
	~window() {}
	virtual void input_callback();
};


#endif
