#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "vertices.hpp"
#include "shader.hpp"
#include "animate.hpp"
#include "texture.hpp"

class shape : public shader, public texture, public animate
{
protected:
	GLuint EBO;
	GLuint VBO;
	GLuint VAO;
	std::vector<float> VBO_DATA;
	std::vector<unsigned int> indices;
	void data_parser();
public:
	vertices<point> coordinates;
	shape() : VBO(0), VAO(0), EBO(0) {}
	shape(const unsigned &size);
	shape(const shape &other);
	shape(shape &&other) noexcept;
	shape& operator=(const shape &other);
	shape& operator=(shape &&other) noexcept;
	virtual ~shape();
	virtual void buff_handle();
	virtual void render();
	virtual void update() {}
	virtual void draw();
};

#endif 