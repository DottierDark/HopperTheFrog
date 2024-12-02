#include "House.hpp"

House::House() {
	pos = Vector3f(0.0f, 0.0f, 0.0f);
	model.Load("assets/models/House/house.3ds");
	model.scale = 10.0f;
	model.rot.x = 90.0f;
}

House::House(float x, float y, float z) {
	pos = Vector3f(x, y, z);
	model.Load("assets/models/House/house.3ds");
	model.scale = 10.0f;

	model.rot.x = 90.0f;

}

void House::update(float deltaTime) {
	// Update House attributes
}

void House::render() {
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	model.Draw();
	glPopMatrix();
}
