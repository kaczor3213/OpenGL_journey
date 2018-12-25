#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <stb_image.h>
#include <glad.h>
#include <glfw3.h>
#include <string>
#include <iostream>

class Texture {
private:
	int width;
	int height;
	int nrChannels;
protected:
	virtual void generate_texture(const std::string &filepath);
	unsigned char *textureData;
public:
	unsigned int texture1;
	unsigned textureLoc;
	Texture() : texture1(0), textureLoc(0), width(0), height(0), nrChannels(0) {}
	Texture(const std::string &filepath);
	~Texture() { delete[] textureData; }
	void activate_textures();
};

#endif 