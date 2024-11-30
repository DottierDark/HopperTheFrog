#include "GLTexture.h"
#include <iostream>

GLTexture::GLTexture() : textureID(0), width(0), height(0) {}

GLTexture::~GLTexture() {
	if (textureID) {
		glDeleteTextures(1, &textureID);
	}
}

bool GLTexture::Load(const std::string& filepath) {
	textureID = SOIL_load_OGL_texture(filepath.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y);

	if (!textureID) {
		std::cerr << "Failed to load texture: " << filepath << std::endl;
		return false;
	}

	// Set texture parameters
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	return true;
}


void GLTexture::Use() const {
	glBindTexture(GL_TEXTURE_2D, textureID);
}
