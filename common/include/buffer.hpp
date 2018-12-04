//
// Created by Moew34 on 11/18/2018.
//

///make a universal draw function for different shapes
///make a container for several different shapes
#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <glad.h>
#include <glfw3.h>
#include "vertices.hpp"
#include "shape.hpp"
#include "shader.hpp"

class buffer : public shader {
private:
	unsigned EBO;
    unsigned VBO;
    unsigned VAO;
    std::vector<float> VBO_DATA;
public:
    buffer() : VBO(0), VAO(0), EBO(0) {}
    ~buffer();
	void draw();
    void render(shape &set);
};
#endif //BUFFER_HPP
