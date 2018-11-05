#ifndef SHADER_HPP
#define SHADER_HPP

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

shader::shader(const std::string &vertexpath, const std::string &fragmentpath)
{
	std::fstream vertexfile(vertexpath, std::fstream::in);
	std::fstream fragmentfile(fragmentpath, std::fstream::in);
	std::stringstream vertexstream;
	std::stringstream fragmentstream;
	std::string vertexcode;
	std::string fragmentcode;
	vertexfile.exceptions(std::fstream::badbit | std::fstream::failbit);
	fragmentfile.exceptions(std::fstream::badbit | std::fstream::failbit);
	vertexstream << vertexfile.rdbuf();
	fragmentstream << fragmentfile.rdbuf();
	vertexcode = vertexstream.str();
	fragmentcode = fragmentstream.str();
	const char *c_vertexcode = vertexcode.c_str();
	const char *c_fragmentcode = fragmentcode.c_str();
	compile(c_vertexcode, c_fragmentcode);
	delete c_vertexcode;
	delete c_fragmentcode;
}


shader::shader(const shader &other)
{
	shaderProgram = other.shaderProgram;
}

shader& shader::operator=(const shader &other)
{
	return *this = shader(other);
}

shader::shader(shader &&other) noexcept
{
	shaderProgram = std::exchange(other.shaderProgram, 0);
}

shader& shader::operator=(shader &&other) noexcept
{
	std::swap(shaderProgram, other.shaderProgram);
	return *this;
}

shader::~shader()
{
	glDeleteShader(shaderProgram);
}

void shader::compile(const char *c_vertexcode, const char *c_fragmentcode)
{
	glVertexAttribPointer(0, 7, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &c_vertexcode, nullptr);
	glCompileShader(vertexShader);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &c_fragmentcode, nullptr);
	glCompileShader(fragmentShader);
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void shader::run() const
{
	glUseProgram(shaderProgram);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void shader::link_shader(const std::string &vertexpath, const std::string &fragmentpath)
{
	*this = shader(vertexpath, fragmentpath);
}

#endif