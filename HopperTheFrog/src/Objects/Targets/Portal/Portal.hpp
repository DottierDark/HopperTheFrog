#pragma once

#include <iostream>
#include <Utils/Textures/Model_3DS.h>
#include <Utils/Vector3f.h>


class Portal
{
public:
	Portal();
	void render();

private:
	Model_3DS model;
	Vector3f pos;
};

