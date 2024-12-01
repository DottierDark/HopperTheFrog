#include "River.hpp"


River::River(float x, float y, float z) {
	pos = Vector3f(x, y, z);
	model.Load("assets/models/River/river.3ds");
}

void River::update(float deltaTime) {
	// Update River attributes
}

void River::render() {
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	model.Draw();
	glPopMatrix();
}