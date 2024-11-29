#pragma once

#include <iostream>

#include <Utils/Textures/Model_3DS.h>
#include <Utils/Vector3f.h>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

class Car {
public:
	Car();
	Car(float x, float y, float z, float speed);
	void update(float deltaTime);
	void render();

private:
	Model_3DS model;
	Vector3f pos;
	float speed = 0.5f;
};

