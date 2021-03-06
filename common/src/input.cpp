#include "../include/input.hpp"

void init_input(GLFWwindow *&window) {
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

CameraMovement keyboard_callback(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		return FORWARD;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		return BACKWARD;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		return LEFT;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		return RIGHT;
	return NONE;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) { 
	glViewport(0, 0, width, height);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	CurrentScrollPos = yoffset;
}

Vector2d get_mouse_position(GLFWwindow* window) {
	glfwGetCursorPos(window, &CurrentMouseXPos, &CurrentMouseYPos);
	float xoffset = CurrentMouseXPos - LastMouseXPos;
	float yoffset = LastMouseYPos - CurrentMouseYPos;
	LastMouseXPos = CurrentMouseXPos;
	LastMouseYPos = CurrentMouseYPos;
	Vector2d tmp(xoffset, yoffset);
	return tmp;
}

const double get_scroll_position() {
	if (CurrentScrollPos - LastScrollPos > 0)
	{
		CurrentScrollPos = LastScrollPos;
		return 1.0;
	}
	if (CurrentScrollPos - LastScrollPos < 0)
	{
		CurrentScrollPos = LastScrollPos;
		return -1.0;
	}
	return 0.0;
}

std::vector<Point> load_from_file(std::istream& input) {
	std::vector<Point> set;
	Point element;
	std::vector<float> tmp;
	float value;
	while (!input.eof())
	{
		for (unsigned i = 0; i < 3; i++)
		{
			input >> value;
			tmp.push_back(value);
		}
		for (unsigned i = 0; i < 4; i++)
		{
			tmp.push_back(0.f);
		}
		element = Point(tmp);
		set.push_back(element);
		tmp.clear();
	}
	return set;
}

std::vector<float> load_animation(std::istream& input) {
	std::vector<float> set;
	float value;
	while (!input.eof())
	{
		for (unsigned i = 0; i < 3; i++)
		{
			input >> value;
			set.push_back(value);
		}
	}
	return set;
}

std::vector<Point> load_from_file(std::string filePath) {
	std::fstream file;
	file.open(filePath);
	if (!file.is_open())
		throw std::runtime_error("Couldn't open" + filePath + "file!\n");
	return load_from_file(file);
}

std::vector<float> load_animation(std::string filePath) {
	std::fstream file;
	file.open(filePath);
	if (!file.is_open())
		throw std::runtime_error("Couldn't open" + filePath + "file!\n");
	return load_animation(file);
}