#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include <glad.h>
#include <glfw3.h>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "../common/include/quad.hpp"
#include "../common/include/input.hpp"



int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow *window = glfwCreateWindow(800, 600, "Okno", nullptr, nullptr);
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

	init_input(window);

	///tu sie dzieje magia

	const Color COLOR_YELLOW(255, 255, 0, 255);
	const Color COLOR_BLACK(0, 0, 0, 255);
	const Color COLOR_RED(255, 0, 0, 255);
	const Color COLOR_GREEN(0, 255, 0, 255);
	const Color COLOR_BLUE(0, 0, 255, 255);

	Quad my_quad;

	my_quad.coordinates[0].x = -0.5;
	my_quad.coordinates[0].y = 0.5;
	my_quad.coordinates[0].z = -5.0;

	my_quad.coordinates[1].x = -0.5;
	my_quad.coordinates[1].y = -0.5;
	my_quad.coordinates[1].z = -5.0;

	my_quad.coordinates[2].x = 0.5;
	my_quad.coordinates[2].y = -0.5;
	my_quad.coordinates[2].z = -5.0;

	my_quad.coordinates[3].x = 0.5;
	my_quad.coordinates[3].y = 0.5;
	my_quad.coordinates[3].z = -5.0;

	my_quad.coordinates[0].s = 0.0;
	my_quad.coordinates[0].t = 1.0;

	my_quad.coordinates[1].s = 0.0;
	my_quad.coordinates[1].t = 0.0;

	my_quad.coordinates[2].s = 1.0;
	my_quad.coordinates[2].t = 0.0;

	my_quad.coordinates[3].s = 1.0;
	my_quad.coordinates[3].t = 1.0;

	my_quad.set_texture(Texture("profilduo.png"));

	my_quad.render();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		my_quad.handle_input(window);
		my_quad.draw();
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
