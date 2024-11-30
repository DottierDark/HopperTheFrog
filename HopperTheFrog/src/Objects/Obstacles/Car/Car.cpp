#include "Car.hpp"


Car::Car() {
	model.Load("assets/models/Car/Car.3ds");
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	speed = 0;
}

Car::Car(float x, float y, float z, float speed) {
	model.Load("assets/models/Car/Car.3ds");
	pos.x = x;
	pos.y = y;
	pos.z = z;
	this->speed = speed;
}

void Car::update(float deltaTime) {
	// Update car
	pos.x += deltaTime * speed;

}

void Car::render() {
	glPushMatrix();
	// Apply transformations
	glTranslatef(pos.x, pos.y, pos.z);       // Translate to current position
	model.Draw();                     // Render the model
	glPopMatrix();
}