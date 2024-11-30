#include "Portal.hpp"


Portal::Portal() {
	model.loadModel("assets/models/Portal_1.3ds");
}


void Portal::render() {
	glPushMatrix();
	// Apply transformations
	glTranslatef(pos.x, pos.y, pos.z);       // Translate to current position
	glScalef(1.0f, 1.0f, 1.0f);          // Scale if necessary
	model.render();                         // Render the model
	glPopMatrix();
}