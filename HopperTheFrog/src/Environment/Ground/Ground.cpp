#include "Ground.h"


Ground::Ground() {
	texture.Load("assets/textures/ground.bmp"); // Load the ground texture
}

Ground::Ground(const char* textureFile) {
	texture.Load((char*)textureFile); // Load the ground texture
}

void Ground::render() {
	texture.Use(); // Bind the texture
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-500.0f, 0.0f, -500.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(500.0f, 0.0f, -500.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(500.0f, 0.0f, 500.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-500.0f, 0.0f, 500.0f);
	glEnd();
}
