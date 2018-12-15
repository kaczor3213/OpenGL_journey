#include <iostream>
#include <glad.h>
#include <glfw3.h>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "../common/include/quad.hpp"

unsigned SCR_WIDTH = 800;
unsigned SCR_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Okno", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "ERROR WHILE CREATING A WINDOW::EXITING\n";
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		getchar();
		return -1;
	}
	glEnable(GL_DEPTH_TEST);

	///tu sie dzieje magia

	const color COLOR_YELLOW(255, 255, 0, 255);
	const color COLOR_BLACK(0, 0, 0, 255);
	const color COLOR_RED(255, 0, 0, 255);
	const color COLOR_GREEN(0, 255, 0, 255);
	const color COLOR_BLUE(0, 0, 255, 255);

	quad my_quad;
	my_quad.coordinates[0].position[0] = -0.5;
	my_quad.coordinates[0].position[1] = 0.5;
	my_quad.coordinates[0].position[2] = 0.0;

	my_quad.coordinates[1].position[0] = -0.5;
	my_quad.coordinates[1].position[1] = -0.5;
	my_quad.coordinates[1].position[2] = 0.0;

	my_quad.coordinates[2].position[0] = 0.5;
	my_quad.coordinates[2].position[1] = -0.5;
	my_quad.coordinates[2].position[2] = 0.0;

	my_quad.coordinates[3].position[0] = 0.5;
	my_quad.coordinates[3].position[1] = 0.5;
	my_quad.coordinates[3].position[2] = 0.0;

	my_quad.coordinates[0].set_color(COLOR_GREEN);
	my_quad.coordinates[1].set_color(COLOR_BLACK);
	my_quad.coordinates[2].set_color(COLOR_RED);
	my_quad.coordinates[3].set_color(COLOR_BLUE);

	my_quad.render();
	
	
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClearColor(0.5f, 0.4f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		my_quad.draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	SCR_WIDTH = width;
	SCR_HEIGHT = height;
	glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}