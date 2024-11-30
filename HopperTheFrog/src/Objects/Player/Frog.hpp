#pragma once

#include <iostream>
#include <Utils/TexturesAndModels/Model.h>
#include <Utils/Vector3f.h>

#ifndef M_PI

#define M_PI 3.14159265358979323846
#endif // !M_PI


class Frog {
public:

	// Constructor
	Frog();
	Frog(const char* modelPath);

	void update(float deltaTime);                        // Apply movement
	void render();

	// Accessor functions
	float getX() const;
	float getY() const;
	float getZ() const;
	float getRotationY() const;
	float getSpeed() const;

	// Movement control state
	bool moveForwardFlag;
	bool moveBackwardFlag;
	bool turnLeftFlag;
	bool turnRightFlag;

private:
	Model model;
	Vector3f pos;
	float speed;
	float rotationY; // Y-axis rotation


};