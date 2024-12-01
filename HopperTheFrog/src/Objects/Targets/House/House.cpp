#include "House.hpp"

House::House() {
	pos = Vector3f(0.0f, 0.0f, 0.0f);
	model.Load("assets/models/House/house.3ds");
}

void House::update(float deltaTime) {
	// Update House attributes
}

void House::render() {
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	model.Draw();
	glPopMatrix();
}
