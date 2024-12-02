#include "Street.hpp"

Street::Street() {
	model.Load("assets/models/Street/Road.3ds"); // Load the street model
}


Street::Street(float x, float y, float z) {
	pos.x = x;
	pos.y = y;
	pos.z = z;
	model.Load("assets/models/Street/Road.3ds"); // Load the street model

	model.rot.y = 90.0f; // Rotate the street
}


void Street::update(float deltaTime) {
	// Update the street
}

void Street::render() {
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	glScalef(6.0f, 1.0f, 3.0f); // Scale the street
	model.Draw();
	glPopMatrix();
}
