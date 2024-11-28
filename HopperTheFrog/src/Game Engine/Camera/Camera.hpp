#pragma once

#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

// Global variables

extern int windowHeight;
extern int windowWidth;

class Camera {
public:
	Camera();
	void setPosition(float x, float y, float z);
	void setTarget(float x, float y, float z);
	void setUpVector(float x, float y, float z);
	void applyView();

private:
	float posX, posY, posZ; // Camera position
	float targetX, targetY, targetZ; // Target position
	float upX, upY, upZ; // Up vector
};

