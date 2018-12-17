#include <iostream>
#include <glad.h>
#include <glfw3.h>


#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "../common/include/polygon.hpp"
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

	///tu sie dzieje magia

	const color COLOR_YELLOW(255, 255, 0, 255);
	const color COLOR_BLACK(0, 0, 0, 255);
	const color COLOR_RED(255, 0, 0, 255);
	const color COLOR_GREEN(0, 255, 0, 255);
	const color COLOR_BLUE(0, 0, 255, 255);

	polygon my_polygon(8);

	my_polygon.coordinates[0].position[0] = -0.5;
	my_polygon.coordinates[0].position[1] = -0.5;
	my_polygon.coordinates[0].position[2] = 0.0;


	my_polygon.coordinates[1].position[0] = -0.2;
	my_polygon.coordinates[1].position[1] = -0.2;
	my_polygon.coordinates[1].position[2] = 0.0;

	my_polygon.coordinates[2].position[0] = 0.2;
	my_polygon.coordinates[2].position[1] = -0.2;
	my_polygon.coordinates[2].position[2] = 0.0;

	my_polygon.coordinates[3].position[0] = 0.5;
	my_polygon.coordinates[3].position[1] = -0.5;
	my_polygon.coordinates[3].position[2] = 0.0;

	my_polygon.coordinates[4].position[0] = 0.5;
	my_polygon.coordinates[4].position[1] = 0.5;
	my_polygon.coordinates[4].position[2] = 0.0;

	my_polygon.coordinates[5].position[0] = 0.0;
	my_polygon.coordinates[5].position[1] = 0.2;
	my_polygon.coordinates[5].position[2] = 0.0;

	my_polygon.coordinates[6].position[0] = -0.5;
	my_polygon.coordinates[6].position[1] = 0.5;
	my_polygon.coordinates[6].position[2] = 0.0;

	my_polygon.coordinates[7].position[0] = -0.9;
	my_polygon.coordinates[7].position[1] = 0.0;
	my_polygon.coordinates[7].position[2] = 0.0;

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
		glClearColor(0.5f, 0.4f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		my_polygon.move(0.001f, 0.0f, 0.0f);
		my_polygon.rotate(0.1f,0.0f,0.0f,1.0f);
		my_polygon.scale_whole(0.999f);

		my_polygon.draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
