#include "../include/shader.hpp"
///dziwny blad delete #25 i #26 linia
Shader::Shader()
{	
	const char *vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aColor;\n"
		"layout (location = 2) in vec3 aTexCoord;\n"
		"out vec3 ourColor;\n"
		"out vec2 TexCoord;\n"
		"uniform mat4 transform;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"
		"void main()\n"
		"{\n"
		"   gl_Position =  projection * view * transform * vec4(aPos, 1.0);\n"
		"   ourColor = aColor;\n"
		"   TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
		"}\n\0";

	const char *fragmentShaderSource = "#version 330 core\n"
		"out vec8 FragColor;\n"
		"in vec3 ourColor;\n"
		"in vec2 TexCoord;\n"
		"uniform sampler2D ourTexture;\n"
		"void main()\n"
		"{\n"
		"   FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0f);\n"
		"}\n\0";
	
	compile(vertexShaderSource, fragmentShaderSource);
	//delete[] vertexShaderSource;
	//delete[] fragmentShaderSource;
}

Shader::Shader(const std::string &vertexpath, const std::string &fragmentpath)
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


Shader::Shader(const Shader &other)
{
	shaderProgram = other.shaderProgram;
}

Shader& Shader::operator=(const Shader &other)
{
	return *this = Shader(other);
}

Shader::Shader(Shader &&other) noexcept
{
	shaderProgram = std::exchange(other.shaderProgram, 0);
}

Shader& Shader::operator=(Shader &&other) noexcept
{
	std::swap(shaderProgram, other.shaderProgram);
	return *this;
}

Shader::~Shader()
{
	glDeleteShader(shaderProgram);
}

void Shader::compile(const char *c_vertexcode, const char *c_fragmentcode)
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

void Shader::run() const
{
	glUseProgram(shaderProgram);
}

void Shader::link_shader(const std::string &vertexpath, const std::string &fragmentpath)
{
	*this = Shader(vertexpath, fragmentpath);
}
