//
// Created by Moew34 on 11/18/2018.
//

///prepare buffer for EBO indices container
#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <glad.h>
#include <glfw3.h>
#include <array>
#include "vertices.hpp"
#include "shape.hpp"
#include "shader.hpp"

class buffer : public shader {
private:
    unsigned VBO;
    unsigned VAO;
    std::array<float,21> VBO_DATA;
public:
    buffer() : VBO(0), VAO(0) {}
    ~buffer();
	void draw();
    void render(shape &set);
};
#endif //BUFFER_HPP
