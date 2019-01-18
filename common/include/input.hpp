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
#include "point.hpp"

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
std::vector<Point> load_from_file(std::istream& input);
std::vector<Point> load_from_file(std::string filePath);

#endif
