#pragma once

#include <iostream>

#include <Utils/TexturesAndModels/Model.h>
#include <Utils/Vector3f.h>

class Coin {
public:
	Coin();
	Coin(float x, float y, float z);
	void update(float deltaTime);
	void render();

private:
	Model model;
	Vector3f pos;
};