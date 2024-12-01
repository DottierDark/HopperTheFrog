#pragma once

#include <iostream>
#include <cmath>
#include <Utils/TexturesAndModels/Model.h>

#include <Utils/3DModel/Model_3DS.h>
#include <Utils/Vector3f.h>


#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

#ifndef M_PI

#define M_PI 3.14159265358979323846
#endif // !M_PI


class Frog {
public:

	// Constructor
	Frog();
	Frog(float x, float y, float z);

	void update(float deltaTime);                        // Apply movement
	void render();

	// Accessor functions
	float getX() const;
	float getY() const;
	float getZ() const;

	// Movement control functions
	void moveForward();
	void moveBackward();
	void moveLeft();
	void moveRight();

	// Toggle movement state
	void setMoving(bool isMoving);

	float getSpeed() const;

	float getDirectionX() const;
	float getDirectionZ() const;

private:
	Model_3DS model;
	Vector3f pos;
	Vector3f direction;
	bool moving;
	float speed;



};