#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include <glew.h>
#include <SOIL2/SOIL2.h>
#include <string>

class GLTexture {
public:
	GLuint textureID;                     // OpenGL Texture ID
	int width, height;                    // Texture dimensions

	GLTexture();
	~GLTexture();

	bool Load(const std::string& filepath); // Load texture from file using SOIL
	void Use() const;                            // Bind the texture
};

#endif // GLTEXTURE_H
