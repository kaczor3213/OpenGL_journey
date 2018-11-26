//
// Created by Moew34 on 11/18/2018.
//

#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <glad.h>
#include <glfw3.h>
#include "vertices.hpp"

class buffer {
private:
    unsigned VBO;
    unsigned VAO;
    float** VBO_DATA;
    int VBO_DATA_SIZE;
public:
    buffer() : VBO(0), VAO(0), VBO_DATA(nullptr), VBO_DATA_SIZE(0) {}
    ~buffer();
    void set_buffers(const float** data);
	void bind_and_draw();
    void parse_to_glsl(const vertices<point> &set);
};
#endif //BUFFER_HPP
