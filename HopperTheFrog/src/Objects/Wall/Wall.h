#pragma once

#include <Utils/3DModel/Model_3DS.h>
#include <Utils/Vector3f.h>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif // __APPLE__


class Wall
{

public:
	Wall();
	Wall(float x, float y, float z);
	void render();
private:
	Model_3DS model;
	Vector3f pos;

};

