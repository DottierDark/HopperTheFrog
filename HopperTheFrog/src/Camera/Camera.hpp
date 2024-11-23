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
	~Camera();

	void setupCamera();
};