#include "Frog.hpp"



Frog::Frog() {
	speed = 200.0f;

	model.Load("assets/models/frog/frog.3ds");
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = 0.0f;

	moving = false;
	direction = Vector3f(0.0f, 0.0f, 1.0f);

}

Frog::Frog(float x, float y, float z) {

	speed = 200.0f;

	model.Load("assets/models/frog/frog.3ds");
	pos.x = x;
	pos.y = y;
	pos.z = y;

	direction = Vector3f(0.0f, 0.0f, 1.0f);

	moving = false;

}


float Frog::getX() const { return pos.x; }
float Frog::getY() const { return pos.y; }
float Frog::getZ() const { return pos.z; }
float Frog::getSpeed() const { return speed; }

float Frog::getDirectionX() const { return direction.x; }
float Frog::getDirectionZ() const { return direction.z; }


// Toggle movement state
void Frog::setMoving(bool isMoving) {
	moving = isMoving;
}


// Move player forward
void Frog::moveForward() {
	direction = Vector3f(0.0f, 0.0f, -1.0f);
	setMoving(true);
}

// Move player backward
void Frog::moveBackward() {
	direction = Vector3f(0.0f, 0.0f, 1.0f);
	setMoving(true);
}

// Move player left
void Frog::moveLeft() {
	direction = Vector3f(-1.0f, 0.0f, 0.0f);
	setMoving(true);
}

// Move player right
void Frog::moveRight() {
	direction = Vector3f(1.0f, 0.0f, 0.0f);
	setMoving(true);
}


void Frog::update(float deltaTime) {
	if (moving) {
		// Move player in the direction they are facing
		pos = pos + direction * speed * deltaTime;



	}

}


void Frog::render() {
	glPushMatrix();
	// Apply transformations
	glTranslatef(pos.x, pos.y, pos.z);       // Translate to current position
	model.Draw();                         // Render the model
	glPopMatrix();
}


