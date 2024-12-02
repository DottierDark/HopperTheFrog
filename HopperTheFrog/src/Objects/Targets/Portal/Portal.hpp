#pragma once

#include <iostream>

#include <Utils/Vector3f.h>



#ifdef __APPLE__
#include <Utils/TexturesAndModels/Model.h>
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <Utils/3DModel/Model_3DS.h>
#include <GL/glut.h>   // Include GLUT for other platforms
#endif


class Portal
{
public:
	Vector3f pos;
	Portal();
	Portal(float x, float y, float z);
	void render();

private:
	Model_3DS model;
};

