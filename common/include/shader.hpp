#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad.h>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

class shader
{
public:
	void compile(const char *c_vertexcode, const char *c_fragmentcode);
	unsigned shaderProgram;
	shader();
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
