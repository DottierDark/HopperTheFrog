#include "River.hpp"


River::River(float x, float y, float z) {
	pos = Vector3f(x, y, z);
	model.Load("assets/models/River/river.3ds");
	model.rot.y = 90.0f;
}

void River::update(float deltaTime) {
	// Update River attributes
}

void River::render() {
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	glScalef(1.5f, 1.0f, 1.0f);
	model.Draw();
	glPopMatrix();
}