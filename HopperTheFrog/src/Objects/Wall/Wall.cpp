#include "Wall.h"

Wall::Wall() {
	// Set the wall's texture
	model.Load("assets/models/Wall/fence.3ds");
	pos = Vector3f(0.0f, 0.0f, 0.0f);

	model.scale = 10.0f;
}

Wall::Wall(float x, float y, float z) {
	// Set the wall's texture
	model.Load("assets/models/Wall/fence.3ds");
	pos = Vector3f(x, y, z);
	model.scale = 10.0f;

}

void Wall::render() {
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	model.Draw();
	glPopMatrix();
}
