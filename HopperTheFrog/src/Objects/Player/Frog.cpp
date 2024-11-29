#include "Frog.hpp"
#include <cmath>


Frog::Frog() {
	speed = 1.0f;
	rotationY = 0.0f;
	moveForwardFlag = false;
	moveBackwardFlag = false;
	turnLeftFlag = false;
	turnRightFlag = false;
	model.Load("assets/models/frog/frog.3ds");
	pos.x = 0.0f;
	pos.y = 500.0f;
	pos.z = 0.0f;

}

Frog::Frog(const char* modelPath) : speed(1.0f), rotationY(0.0f),
moveForwardFlag(false), moveBackwardFlag(false),
turnLeftFlag(false), turnRightFlag(false) {
	model.Load((char*)modelPath);
	pos.x = 0.0f;
	pos.y = 500.0f;
	pos.z = 0.0f;

}


void Frog::update(float deltaTime) {
	float dx = 0.0f, dz = 0.0f;

	// Determine movement direction based on flags
	if (moveForwardFlag) {
		dx += sin(rotationY * M_PI / 180.0f) * speed * deltaTime;
		dz += cos(rotationY * M_PI / 180.0f) * speed * deltaTime;
	}
	if (moveBackwardFlag) {
		dx -= sin(rotationY * M_PI / 180.0f) * speed * deltaTime;
		dz -= cos(rotationY * M_PI / 180.0f) * speed * deltaTime;
	}
	if (turnLeftFlag) {
		dx += cos(rotationY * M_PI / 180.0f) * speed * deltaTime;
		dz -= sin(rotationY * M_PI / 180.0f) * speed * deltaTime;
	}
	if (turnRightFlag) {
		dx -= cos(rotationY * M_PI / 180.0f) * speed * deltaTime;
		dz += sin(rotationY * M_PI / 180.0f) * speed * deltaTime;
	}

	// Update position
	pos.x += dx;
	pos.z += dz;

	// Automatically adjust rotation to face direction of motion
	if (dx != 0.0f || dz != 0.0f) {
		rotationY = atan2(dx, dz) * 180.0f / M_PI;
	}
}


void Frog::render() {
	glPushMatrix();
	// Apply transformations
	glTranslatef(pos.x, pos.y, pos.z);       // Translate to current position
	glRotatef(rotationY, 0.0f, 1.0f, 0.0f); // Rotate around Y-axis
	glScalef(1.0f, 1.0f, 1.0f);          // Scale if necessary
	model.Draw();                         // Render the model
	glPopMatrix();
}

float Frog::getX() const { return pos.x; }
float Frog::getY() const { return pos.y; }
float Frog::getZ() const { return pos.z; }
float Frog::getRotationY() const { return rotationY; }
float Frog::getSpeed() const { return speed; }

