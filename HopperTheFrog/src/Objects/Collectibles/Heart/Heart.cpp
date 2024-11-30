#include "Heart.hpp"

Heart::Heart() {
	model.Load("assets/models/heart/heart.3ds");
}

Heart::Heart(float x, float y, float z) {
	model.Load("assets/models/heart/heart.3ds");
	pos.x = x;
	pos.y = y;
	pos.z = z;
}

void Heart::update(float deltaTime) {
	// Update coin
	pos.y += 0.5f * deltaTime;
}

void Heart::render() {
	glPushMatrix();
	// Apply transformations
	glTranslatef(pos.x, pos.y, pos.z);       // Translate to current position
	model.Draw();                       // Render the model
	glPopMatrix();
}


