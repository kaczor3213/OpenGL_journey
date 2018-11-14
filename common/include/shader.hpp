#ifndef SHADER_HPP
#define SHADER_HPP

#include "GL/glew.h"

#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

class shader
{
private:
	unsigned vertexShader;
	unsigned fragmentShader;
	unsigned shaderProgram;
	void compile(const char *c_vertexcode, const char *c_fragmentcode);
public:
	shader() : vertexShader(0), fragmentShader(0), shaderProgram(0) {};
	shader(const std::string &vertexpath, const std::string &fragmentpath);
	shader(const shader &other);
	shader& operator=(const shader &other);
	shader(shader &&other) noexcept;
	shader& operator=(shader &&other) noexcept;
	~shader();	
	void run() const;
	void link_shader(const std::string &vertexpath, const std::string &fragmentpath);
};

#endif