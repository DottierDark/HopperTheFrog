#pragma once

#include<Utils/3DModel/Model_3DS.h>
#include<Utils/Vector3f.h>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

class LilyPad
{

public:
	LilyPad();
	LilyPad(float x, float y, float z);
	void render();
	void update(float deltaTime);
	Vector3f pos;
private:
	Model_3DS model;


};

