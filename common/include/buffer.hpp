//
// Created by Moew34 on 11/18/2018.
//

#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <glad.h>
#include <glfw3.h>
#include "vertices.hpp"
#include "shape.hpp"
#include "shader.hpp"

class buffer : public shader {
private:
    unsigned VBO;
    unsigned VAO;
    float* VBO_DATA;
    int VBO_DATA_SIZE;
public:
    buffer() : VBO(0), VAO(0), VBO_DATA(nullptr), VBO_DATA_SIZE(0) {}
    ~buffer();
    void set_buffers();
	void bind_and_draw();
    void parse_to_glsl(shape &set);
};
#endif //BUFFER_HPP
