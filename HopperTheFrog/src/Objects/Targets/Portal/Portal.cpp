#include "Portal.hpp"


Portal::Portal() {
	model.Load("assets/models/Portal_1.3ds");
	model.pos.x = -300;
	model.pos.y = 0;
	model.pos.z = 0;

	model.scale = 10.0f;

}


void Portal::render() {
	model.Draw();
}