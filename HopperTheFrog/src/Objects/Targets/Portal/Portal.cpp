#include "Portal.hpp"


Portal::Portal() {
	model.loadModel("assets/models/Portal_1.3ds");
	pos.x = 300;
	pos.y = 0;
	pos.z = 0;

}


void Portal::render() {
	glPushMatrix();
	// Apply transformations
	glTranslatef(pos.x, pos.y, pos.z);       // Translate to current position
	glScalef(10.0f, 10.0f, 100.0f);          // Scale if necessary
	model.render();                         // Render the model
	glPopMatrix();
}