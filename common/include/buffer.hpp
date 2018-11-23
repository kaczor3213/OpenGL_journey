//
// Created by Moew34 on 11/18/2018.
//

#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <glad.h>
#include <GLFW/glfw3.h>
#include "vertices.hpp"

class buffer {
private:
    unsigned VBO;
    unsigned VAO;
    float** VBO_DATA;
    int VBO_DATA_SIZE;
public:
    buffer() : VBO(0), VAO(0), VBO_DATA(nullptr) {}
    ~buffer();
    void VBO_handling(const float** data);
    void linking_vertex_attributes();
    void bind_VAO();
    void VAO_handling();
    void parse_to_glsl(const vertices<point> &set);
};
#endif //BUFFER_HPP
