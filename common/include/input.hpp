#ifndef INPUT_HPP
#define INPUT_HPP

#include <glad.h>
#include <glfw3.h>
#include <fstream>
#include <vector>
#include <string>
#include <exception>
#include "vector2d.hpp"
#include "camera.hpp"
#include "vertices.hpp"

static unsigned SCR_WIDTH = 800;
static unsigned SCR_HEIGHT = 600;
static double CurrentMouseXPos = 0;
static double CurrentMouseYPos = 0;
static double LastMouseXPos = 0;
static double LastMouseYPos = 0;
static double CurrentScrollPos = 0;
static double LastScrollPos = 0;

void init_input(GLFWwindow *&window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
CameraMovement keyboard_callback(GLFWwindow *window);
Vector2d get_mouse_position();
const double get_scroll_position();


template <typename T>
Vertices<T> load_from_file(std::istream& input) {
	std::vector<Point> set;
	Point element;
	std::vector<T> tmp;
	T value;

	while (!input.eof())
	{
		for (unsigned i = 0; i < 7; i++)
		{
			input >> value;
			tmp.push_back(value);
			input.ignore(1);
		}
		element = Point(tmp);
		set.push_back(element);
		tmp.clear();
	}
	
	return set;
}

template <typename T>
Vertices<T> load_from_file(std::string filePath) {
	std::fstream file;
	file.open(filePath);
	if (!file.is_open())
		throw std::runtime_error("Couldn't open" + filePath + "file!\n");
	return load_from_file<T>(file);
}


#endif
