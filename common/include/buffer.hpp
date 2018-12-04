//
// Created by Moew34 on 11/18/2018.
//

///make a universal draw function for different shapes
///fix all buffering process for multiple data
#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <glad.h>
#include <glfw3.h>
#include "vertices.hpp"
#include "shape.hpp"
#include "shader.hpp"

class buffer : public shader {
private:
	GLuint *EBO;
	GLuint *VBO;
	GLuint *VAO;
    std::vector<float> VBO_DATA;
	std::vector<shape> set;
	unsigned figure_count;
public:
    buffer() : VBO(nullptr), VAO(nullptr), EBO(nullptr), figure_count(0) {}
    ~buffer();
	void add(shape &figure);
	void draw();
    void render();
};
#endif //BUFFER_HPP
