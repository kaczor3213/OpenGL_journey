#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include <glad.h>
#include <glfw3.h>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "../common/include/cube.hpp"
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
	

	Cube my_cube;
	my_cube.generate();
	my_cube.render_cube();



	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.5f, 0.4f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		my_cube.process_keyboard(keyboard_callback(window), 0.005f);
		my_cube.process_mouse_movement(get_mouse_position(), true);
		my_cube.process_mouse_scroll(get_scroll_position());
		my_cube.get_view();

		my_cube.draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
