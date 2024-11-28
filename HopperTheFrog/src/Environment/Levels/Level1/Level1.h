#pragma once

#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <Utils/Textures/Model_3DS.h>
#include  <Utils/Textures/GLTexture.h>

#include <Game Engine/Camera/Camera.hpp>
#include <Game Engine/Lighting/Lighting.hpp>

#include <GL/glut.h>   // Include GLUT for other platforms
#endif



class Level1 {
public:
	Level1();
	void update(float deltaTime);
	void render();

private:
	void RenderGround();
	void LoadAssets();
	// Add Level1 attributes
	Camera camera;
	Lighting lighting;
	Model_3DS street;
	GLTexture tex_ground;
};

