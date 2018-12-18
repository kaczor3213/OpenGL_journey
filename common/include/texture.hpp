#ifndef TEXTURES_HPP
#define TEXTURES_HPP

//pamietaj o dodaniu tego headera do externali, ktory Ci wyslalem
//zapomnialem zmienic parsera, ale mowiles, ze zmiensiz vector3d, wiec to sie dogra spokojnie

#include <glad.h>
#include "stb_image.h"
#include <string>
#include <iostream>

class texture {
public:
	unsigned textureID;
	unsigned textureLoc;
	int width;
	int height;
	int nrChannels;
	unsigned char *data;
	std::string path;
	texture() : textureID(0), textureLoc(0), width(0), height(0), nrChannels(0), data(nullptr), path("") {}
	~texture();
	void set_path(const std::string &filepath);
	void generate_texture();
	void activate_textures();
};

#endif 