#pragma once

#include <Game Engine/Camera/Camera.hpp>
#include <Game Engine/Lighting/Lighting.hpp>

#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

class Level2 {
public:
	Level2();
	void update(float deltaTime);
	void render();

private:
	// Add Level1 attributes
	Camera camera;
	Lighting lighting;
};

