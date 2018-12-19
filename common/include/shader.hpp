#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad.h>
#include <glfw3.h>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

class Shader
{
protected:
	unsigned shaderProgram;
public:
	
	Shader();
	Shader(const std::string &vertexpath, const std::string &fragmentpath);
	Shader(const Shader &other);
	Shader& operator=(const Shader &other);
	Shader(Shader &&other) noexcept;
	Shader& operator=(Shader &&other) noexcept;
	~Shader();
	void compile(const char *c_vertexcode, const char *c_fragmentcode);
	void run() const;
	void link_shader(const std::string &vertexpath, const std::string &fragmentpath);
};

#endif
