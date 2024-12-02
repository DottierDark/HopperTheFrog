#include "Coin.hpp"

Coin::Coin() {
	model.Load("assets/models/Coin/coin.3ds");
}

Coin::Coin(float x, float y, float z) {
	model.Load("assets/models/Coin/coin.3ds");
	pos.x = x;
	pos.y = y;
	pos.z = z;

	baseY = y;

	model.scale = 3.0f;
}

void Coin::update(float deltaTime) {
	float oscillationHeight = 5.0f; // How far above and below the base y the coin should move
	float frequency = 2.0f;         // Speed of oscillation

	static float time = 0.0f; // Tracks elapsed time for oscillation
	time += deltaTime;
	// Oscillate around the current y as the base position
	pos.y = baseY + (oscillationHeight * std::sin(time * frequency));
}

void Coin::render() {
	glPushMatrix();
	// Apply transformations
	glTranslatef(pos.x, pos.y, pos.z);       // Translate to current position
	model.Draw();                       // Render the model
	glPopMatrix();
}


