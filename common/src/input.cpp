#include "../include/input.hpp"

void init_input(GLFWwindow *&window)
{
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

CameraMovement keyboard_callback(GLFWwindow *window)
{
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


void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	CurrentMouseXPos = xpos;
	CurrentMouseYPos = ypos;
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	CurrentScrollPos = yoffset;
}

Vector2d get_mouse_position() {
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