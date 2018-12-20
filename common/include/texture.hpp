#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "stb_image.h"
#include <glad.h>
#include <string>
#include <iostream>

class Texture {
private:
	int width;
	int height;
	int nrChannels;
protected:
	virtual void generate_texture();
	unsigned char *textureData;
public:
	unsigned int textureID;
	unsigned textureLoc;
	Texture() : textureID(0), textureLoc(0), width(0), height(0), nrChannels(0) {}
	Texture(const std::string &filepath);
	~Texture() { delete[] textureData; }
	void set_path(const std::string &filepath);
	void activate_textures();
};

#endif 