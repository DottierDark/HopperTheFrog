#pragma once

#include <iostream>

#include <Utils/Vector3f.h>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

#ifndef M_PI

#define M_PI 3.14159265358979323846
#endif // !M_PI


// Global variables

extern int windowHeight;
extern int windowWidth;

class Camera {
public:
	enum ViewType { FIRST_PERSON, THIRD_PERSON };

	Camera();

	Camera(float eyeX, float eyeY, float eyeZ,
		float centerX, float centerY, float centerZ,
		float upX, float upY, float upZ);

	void toggleView(float playerX, float playerY, float playerZ, float playerRotY);
	void applyView();

	void moveX(float d);
	void moveY(float d);
	void moveZ(float d);

private:
	Vector3f eye;
	Vector3f center;
	Vector3f up;
	ViewType currentView;

	void setFOV(float fov);

};
