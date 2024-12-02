#pragma once

#include <iostream>

#include <Utils/3DModel/Model_3DS.h>
#include <Utils/Vector3f.h>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

class Heart {
public:
	Heart();
	Heart(float x, float y, float z);
	void update(float deltaTime);
	void render();
	Vector3f pos;

private:
	Model_3DS model;
	float baseY;
};