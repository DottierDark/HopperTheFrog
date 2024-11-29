#pragma once
#include <Utils/Textures/GLTexture.h>

class Ground {
public:
	Ground();
	Ground(const char* textureFile);
	void render();

private:
	GLTexture texture; // Use the provided texture loader
};

