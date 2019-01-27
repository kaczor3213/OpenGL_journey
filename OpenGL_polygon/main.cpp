#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include <glad.h>
#include <glfw3.h>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "../common/include/field.hpp"
#include "../common/include/input.hpp"

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
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		getchar();
		return -1;
	}

	glEnable(GL_DEPTH_TEST);

	///tu sie dzieje magia

	const Color COLOR_YELLOW(255, 255, 0, 255);
	const Color COLOR_BLACK(0, 0, 0, 255);
	const Color COLOR_RED(255, 0, 0, 255);
	const Color COLOR_GREEN(0, 255, 0, 255);
	const Color COLOR_BLUE(0, 0, 255, 255);

	Field my_polygon(8);

	my_polygon.coordinates[0].x = -0.5;
	my_polygon.coordinates[0].y = -0.5;
	my_polygon.coordinates[0].z = 0.0;

	my_polygon.coordinates[1].x = -0.2;
	my_polygon.coordinates[1].y = -0.2;
	my_polygon.coordinates[1].z = 0.0;

	my_polygon.coordinates[2].x = 0.2;
	my_polygon.coordinates[2].y = -0.2;
	my_polygon.coordinates[2].z = 0.0;

	my_polygon.coordinates[3].x = 0.5;
	my_polygon.coordinates[3].y = -0.5;
	my_polygon.coordinates[3].z = 0.0;

	my_polygon.coordinates[4].x = 0.5;
	my_polygon.coordinates[4].y = 0.5;
	my_polygon.coordinates[4].z = 0.0;

	my_polygon.coordinates[5].x = 0.0;
	my_polygon.coordinates[5].y = 0.2;
	my_polygon.coordinates[5].z = 0.0;

	my_polygon.coordinates[6].x = -0.5;
	my_polygon.coordinates[6].y = 0.5;
	my_polygon.coordinates[6].z = 0.0;

	my_polygon.coordinates[7].x = -0.9;
	my_polygon.coordinates[7].y = 0.0;
	my_polygon.coordinates[7].z = 0.0;

	my_polygon.coordinates[0].set_color(COLOR_GREEN);
	my_polygon.coordinates[1].set_color(COLOR_BLACK);
	my_polygon.coordinates[2].set_color(COLOR_RED);
	my_polygon.coordinates[3].set_color(COLOR_BLUE);
	my_polygon.coordinates[4].set_color(COLOR_YELLOW);
	my_polygon.coordinates[5].set_color(COLOR_RED);
	my_polygon.coordinates[6].set_color(COLOR_BLUE);
	my_polygon.coordinates[7].set_color(COLOR_YELLOW);

	my_polygon.render();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		my_polygon.draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}