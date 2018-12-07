#ifndef SHAPE_HPP
#define SHAPE_HPP

<<<<<<< HEAD
#include "vertices.hpp"

class shape
{
public:
	std::vector<unsigned int> indices;
	vertices<point> coordinates;
	shape() {}
	shape(const unsigned &vertices_count);
	virtual ~shape() {}
};


=======
#include "shader.hpp"
#include "vertices.hpp"

class shape : public shader
{
protected:
	GLuint EBO;
	GLuint VBO;
	GLuint VAO;
	std::vector<float> VBO_DATA;
	std::vector<unsigned int> indices;
	void data_parser();
	void buff_handle();
public:
	vertices<point> coordinates;
	shape() : VBO(0), VAO(0), EBO(0) {}
	shape(const unsigned &size);
	shape(const shape &other);
	shape(shape &&other) noexcept;
	shape& operator=(const shape &other);
	shape& operator=(shape &&other) noexcept;
	virtual ~shape();
	virtual void render();
	virtual void update() {}
	virtual void draw();
};

>>>>>>> dev
#endif 