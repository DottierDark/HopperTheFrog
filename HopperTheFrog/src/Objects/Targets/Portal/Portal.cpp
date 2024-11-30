#include "Portal.hpp"


Portal::Portal() {
	model.Load("assets/models/Portal/Portal_1.3ds");
	model.pos.x = 0;
	model.pos.y = 0;
	model.pos.z = 0;

	model.scale = 10.0f;

}

Portal::Portal(float x, float y, float z) {
	model.Load("assets/models/Portal/Portal_1.3ds");
	model.pos.x = x;
	model.pos.y = y;
	model.pos.z = z;

	model.scale = 10.0f;
}


void Portal::render() {
	model.Draw();
}