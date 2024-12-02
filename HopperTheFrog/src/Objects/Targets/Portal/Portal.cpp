#include "Portal.hpp"


Portal::Portal() {
	model.Load("assets/models/Portal/Portal_1.3ds");
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;

	model.scale = 10.0f;

}

Portal::Portal(float x, float y, float z) {
	model.Load("assets/models/Portal/Portal_1.3ds");
	pos.x = x;
	pos.y = y;
	pos.z = z;

	model.scale = 10.0f;
	model.rot.y = -90.0f;
}


void Portal::render() {
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);

	model.Draw();
	glPopMatrix();
}