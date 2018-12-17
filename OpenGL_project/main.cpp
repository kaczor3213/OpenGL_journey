#include <iostream>
#include <glad.h>
#include <glfw3.h>
#include <glm.hpp>

#include "../common/include/triangle.hpp"
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
	
	const color COLOR_RED(255, 0, 0, 255);
	const color COLOR_GREEN(0, 255, 0, 255);
	const color COLOR_BLUE(0, 0, 255, 255);
	
	triangle my_triangle;

	my_triangle.coordinates[0].position[0] = -0.5;
	my_triangle.coordinates[0].position[1] = -0.5;
	my_triangle.coordinates[0].position[2] = 0.0;

	my_triangle.coordinates[1].position[0] = 0.5;
	my_triangle.coordinates[1].position[1] = -0.5;
	my_triangle.coordinates[1].position[2] = 0.0;

	my_triangle.coordinates[2].position[0] = 0.0;
	my_triangle.coordinates[2].position[1] = 0.5;
	my_triangle.coordinates[2].position[2] = 0.0;

	my_triangle.coordinates[0].set_color(COLOR_RED);
	my_triangle.coordinates[1].set_color(COLOR_GREEN);
	my_triangle.coordinates[2].set_color(COLOR_BLUE);

	
	my_triangle.render();

    while (!glfwWindowShouldClose(window))
    {
		glClearColor(0.5f, 0.4f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		my_triangle.draw();

		glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}