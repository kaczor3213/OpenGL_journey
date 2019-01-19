#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "vertices.hpp"
#include "shader.hpp"
#include "animate.hpp"
#include "texture.hpp"
#include "input.hpp"

class Shape : public Shader, public Animate
{
protected:
	Texture texture;
	GLuint EBO;
	GLuint VBO;
	GLuint VAO;
	std::vector<float> VBO_DATA;
	std::vector<unsigned int> indices;
	void data_parser();
	virtual void buff_handle();
public:
	std::vector<Point> coordinates;
	Shape() : VBO(0), VAO(0), EBO(0) {}
	Shape(const unsigned &size);
	Shape(const Shape &other);
	Shape(Shape &&other) noexcept;
	Shape& operator=(const Shape &other);
	Shape& operator=(Shape &&other) noexcept;
	virtual ~Shape();
	virtual void handle_input(GLFWwindow *&window);
	virtual void set_shape_color(const Color &COLOR);
	virtual void set_texture(const Texture &TEXTURE);
	virtual void render();
	virtual void update() {}
	virtual void draw();
};

#endif 