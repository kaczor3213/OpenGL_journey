#ifndef SHADER_HPP
#define SHADER_HPP

#include <fstream>
#include <string>
#include <sstream>

//file streaming

class shader
{
private:
	std::string _vertexShader;
	std::string _fragmentShader;
	unsigned vertexShader;
	unsigned fragmentShader;
	unsigned shaderProgram;
	void compile();
public:
	void run();
	shader() {}
	shader(const std::string vertexpath, const std::string fragmentpath);
	shader(const shader &other);
	shader& operator=(const shader &other);
	shader(shader &&other) noexcept;
	shader& operator=(shader &&other) noexcept;
	~shader();	
};

shader::shader(color _color)
{

	_vertexShader = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	_fragmentShader = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4("
		+ _color.get_buffer() +
		");\n"
		"}\n\0";

	compile();
}

shader::shader(const shader &other)
{
	_vertexShader = other._vertexShader;
	_fragmentShader = other._fragmentShader;
	compile();
}

shader& shader::operator=(const shader &other)
{
	_vertexShader.clear();
	_fragmentShader.clear();
	_vertexShader = other._vertexShader;
	_fragmentShader = other._fragmentShader;
	compile();
}

shader::shader(shader &&other) noexcept
{
	_vertexShader = other._vertexShader;
	_fragmentShader = other._fragmentShader;
	other._vertexShader.clear();
	other._fragmentShader.clear();
	compile();
}

shader& shader::operator=(shader &&other) noexcept
{
	_vertexShader.clear();
	_fragmentShader.clear();
	_vertexShader = other._vertexShader;
	_fragmentShader = other._fragmentShader;
	other._vertexShader.clear();
	other._fragmentShader.clear();
	compile();
	return *this;
}

shader::~shader()
{
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void shader::compile()
{
	char *vertexShaderSource = new char[_vertexShader.length()];
	char *fragmentShaderSource = new char[_fragmentShader.length()];

	std::strcpy(vertexShaderSource, _vertexShader.c_str());
	std::strcpy(fragmentShaderSource, _fragmentShader.c_str());
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShader);
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	delete vertexShaderSource;
	delete fragmentShaderSource;
}

void shader::run()
{
	glUseProgram(shaderProgram);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

#endif