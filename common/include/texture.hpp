#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <glad.h>
#include "../stb_image/stb_image.h"
#include <string>
#include <iostream>

class Texture {
public:
	unsigned textureID;
	unsigned textureLoc;
	int width;
	int height;
	int nrChannels;
	std::basic_string<unsigned char> data;
	Texture() : textureID(0), textureLoc(0), width(0), height(0), nrChannels(0) {}
	~Texture() {}
	void set_path(const std::string &filepath);
	void generate_texture();
	void activate_textures();
};

#endif 