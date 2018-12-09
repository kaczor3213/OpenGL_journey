#include "../include/shader.hpp"
///dziwny blad delete #25 i #26 linia
shader::shader()
{	
	const char *vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aColor;\n"
		"out vec3 ourColor;\n"
		"uniform mat4 model;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
		"   ourColor = aColor;\n"
		"}\n\0";

	const char *fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"in vec3 ourColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(ourColor, 1.0f);\n"
		"}\n\0";
	
	compile(vertexShaderSource, fragmentShaderSource);
	//delete[] vertexShaderSource;
	//delete[] fragmentShaderSource;
}

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
	unsigned vertexShader;
	unsigned fragmentShader;
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
}

void shader::link_shader(const std::string &vertexpath, const std::string &fragmentpath)
{
	*this = shader(vertexpath, fragmentpath);
}
