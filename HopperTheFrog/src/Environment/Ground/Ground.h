#pragma once
#include <Utils/TexturesAndModels/GLTexture.h>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

class Ground {
public:
	Ground();
	Ground(const char* textureFile);
	void render();

private:
	GLTexture texture; // Use the provided texture loader
};

