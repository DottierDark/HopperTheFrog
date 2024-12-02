#pragma once
#include <Utils/Vector3f.h>
#include <Utils/3DModel/Model_3DS.h>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif


class House
{
public:
	House();
	House(float x, float y, float z);
	void render();
	void update(float deltaTime);
	Vector3f pos;

private:
	Model_3DS model;
};

