#pragma once

#include <iostream>
#include <Utils/TexturesAndModels/Model.h>
#include <Utils/Vector3f.h>

#include <Utils/3DModel/Model_3DS.h>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif


class Portal
{
public:
	Portal();
	Portal(float x, float y, float z);
	void render();

private:
	Model_3DS model;
	Vector3f pos;
};

