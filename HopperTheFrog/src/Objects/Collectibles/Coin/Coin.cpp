#include "Coin.hpp"

Coin::Coin() {
	model.Load("assets/models/Coin/coin.3ds");
}

Coin::Coin(float x, float y, float z) {
	model.Load("assets/models/Coin/coin.3ds");
	pos.x = x;
	pos.y = y;
	pos.z = z;
}

void Coin::update(float deltaTime) {
	// Update coin
	pos.y += 0.5f * deltaTime;
}

void Coin::render() {
	glPushMatrix();
	// Apply transformations
	glTranslatef(pos.x, pos.y, pos.z);       // Translate to current position
	model.Draw();                       // Render the model
	glPopMatrix();
}


