#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <vector>
#include <iostream>
#include "vertex.hpp"
#include "color.hpp"
#include "shader.hpp"


//dorobic system parsowania wspolrzednych
//poprawic parser kolorow
//dorobic klase buffor
//zrobic interfejs buffor<=>trojkat
/*
	void pix2double()
	{
		for (auto &vertice : vertices) {
			vertice.x = 1.0f / SCR_WIDTH * 2.0f * vertice.x;
			vertice.y = 1.0f / SCR_HEIGHT * 2.0f * vertice.y;
		}
	}
*/

unsigned SCR_WIDTH = 800;
unsigned SCR_HEIGHT = 600;

class triangle {
private:
	color _color;
	shader _shader;
public:
	triangle()
	{
		_color = COLOR_BLUE;
		_shader = shader(_color);
	}
	void draw()
	{
		_shader.run();
	}
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main(void)
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

	triangle my_triangle;
	

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	unsigned VBO, VAO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClearColor(0.5f, 0.4f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		my_triangle.draw();
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