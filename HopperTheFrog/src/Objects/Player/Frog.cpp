#include "Frog.hpp"



Frog::Frog() {
	speed = 200.0f;

	model.loadModel("assets/models/frog/frog.3ds");
	pos.x = 0.0f;
	pos.y = 100.0f;
	pos.z = 0.0f;

	moving = false;
	direction = Vector3f(0.0f, 0.0f, 1.0f);

}

Frog::Frog(const char* modelPath) {

	speed = 200.0f;

	model.loadModel((char*)modelPath);
	pos.x = 0.0f;
	pos.y = 100.0f;
	pos.z = 0.0f;

	direction = Vector3f(0.0f, 0.0f, 1.0f);

	moving = false;

}

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
	// Calculate the rotation angle to face the direction of movement
	if (direction.x == 1.0f) {
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	}
	else if (direction.x == -1.0f) {
		glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	}
	else if (direction.z == -1.0f) {
		glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	}
	else {
		glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
	}
	glScalef(0.5f, 0.5f, 0.5f);          // Scale if necessary
	model.render();                         // Render the model
	glPopMatrix();
}

float Frog::getX() const { return pos.x; }
float Frog::getY() const { return pos.y; }
float Frog::getZ() const { return pos.z; }
float Frog::getSpeed() const { return speed; }

