#include "Portal.hpp"


Portal::Portal() {
	model.Load("assets/models/portal/Portal_1.3ds");
}


void Portal::render() {
	glPushMatrix();
	// Apply transformations
	glTranslatef(pos.x, pos.y, pos.z);       // Translate to current position
	glScalef(1.0f, 1.0f, 1.0f);          // Scale if necessary
	model.Draw();                         // Render the model
	glPopMatrix();
}