#include <iostream>
#include "Coin.hpp"

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif


Coin::Coin() {
	model.Load("assets/models/coin/Coin.3ds");
}

Coin::Coin(float x, float y, float z) {
	model.Load("assets/models/coin/Coin.3ds");
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
	glScalef(1.0f, 1.0f, 1.0f);          // Scale if necessary
	model.Draw();                         // Render the model
	glPopMatrix();
}


