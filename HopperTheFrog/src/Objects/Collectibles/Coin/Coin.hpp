#pragma once

#include <iostream>

#include <Utils/3DModel/Model_3DS.h>
#include <Utils/Vector3f.h>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

class Coin {
public:
	Coin();
	Coin(float x, float y, float z);
	void update(float deltaTime);
	void render();

private:
	Model_3DS model;
	Vector3f pos;
};