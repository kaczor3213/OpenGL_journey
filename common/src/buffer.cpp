//
// Created by Moew34 on 11/18/2018.
//
#include "../include/buffer.hpp"
///buffer parser needs upgrade
buffer::~buffer()
{
    for(int i = 0; i < VBO_DATA_SIZE; i++)
        delete[] VBO_DATA[i];
    delete[] VBO_DATA;
}
void buffer::VBO_handling(const float** data)
{
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}
void buffer::linking_vertex_attributes()
{
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}
void buffer::bind_VAO()
{
    glBindVertexArray(VAO);
}
void buffer::VAO_handling()
{
    glGenVertexArrays(1, &VAO);
    bind_VAO();
}

void buffer::parse_to_glsl(const vertices<point> &set)
{

    VBO_DATA = new float*[set.size()];
    VBO_DATA_SIZE = set.size();
    for (int i=0; i< VBO_DATA_SIZE; i++)
        VBO_DATA[i] = new float[7];

    for (int i = 0; i < VBO_DATA_SIZE; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (j < 3)
                VBO_DATA[i][j] = static_cast<float>(set[j].position[j]);
            else
                VBO_DATA[i][j] = static_cast<float>(set[i].get_color().pigments[j-3]);
        }
    }
}
