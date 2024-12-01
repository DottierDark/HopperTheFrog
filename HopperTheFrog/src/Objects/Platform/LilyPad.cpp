#include "LilyPad.h"


LilyPad::LilyPad() {
	pos = Vector3f(0, 0, 0);
	model.Load("assets/models/Lily pads/water lily.3ds");

	model.scale = 0.1f;
}


LilyPad::LilyPad(float x, float y, float z) {
	pos = Vector3f(x, y, z);
	model.Load("assets/models/Lily pads/water lily.3ds");

	model.scale = 0.1f;
}


void LilyPad::update(float deltaTime) {
	// Do nothing
}



void LilyPad::render() {
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	model.Draw();
	glPopMatrix();
}