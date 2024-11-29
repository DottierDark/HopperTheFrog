#pragma once

#include <iostream>

#include <Utils/Textures/Model_3DS.h>
#include <Utils/Vector3f.h>

class Coin {
public:
	Coin();
	Coin(float x, float y, float z);
	void update(float deltaTime);
	void render();

private:
	Model_3DS model;
	Vector3f pos;
};