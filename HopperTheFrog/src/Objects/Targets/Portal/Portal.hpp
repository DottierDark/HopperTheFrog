#pragma once

#include <iostream>
#include <Utils/TexturesAndModels/Model.h>
#include <Utils/Vector3f.h>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif


class Portal
{
public:
	Portal();
	void render();

private:
	Model model;
	Vector3f pos;
};

