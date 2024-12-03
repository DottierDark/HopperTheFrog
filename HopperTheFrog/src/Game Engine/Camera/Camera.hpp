#pragma once

#include <Utils/Vector3f.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

enum ViewType { FIRST_PERSON, THIRD_PERSON };

class Camera {
private:
	Vector3f eye;
	Vector3f center;
	Vector3f up;
	ViewType currentView;
	int FOV;

public:
	Camera();
	Camera(float eyeX, float eyeY, float eyeZ,
		float centerX, float centerY, float centerZ,
		float upX, float upY, float upZ);

	void applyView();
	void update(float playerX, float playerY, float playerZ, float playerRotY);
	void toggleView();
};


