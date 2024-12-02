#include "Car.hpp"


Car::Car() {
	model.Load("assets/models/Car/Car.3ds");
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	speed = 200;
	model.scale = 5.0f;
	model.rot.y = -90.0f;
}

Car::Car(float x, float y, float z) {
	model.Load("assets/models/Car/Car.3ds");
	pos.x = x;
	pos.y = y;
	pos.z = z;
	speed = 200;

	model.scale = 5.0f;
	model.rot.y = -90.0f;
}

bool Car::reachedEnd() {
	return pos.x < -200;
}

void Car::update(float deltaTime) {
	// Update car
	pos.x -= deltaTime * speed;
}

void Car::render() {
	glPushMatrix();
	// Apply transformations
	glTranslatef(pos.x, pos.y, pos.z);       // Translate to current position
	model.Draw();                     // Render the model
	glPopMatrix();
}