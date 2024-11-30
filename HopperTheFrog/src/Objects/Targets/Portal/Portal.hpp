#pragma once

#include <iostream>
#include <Utils/TexturesAndModels/Model.h>
#include <Utils/Vector3f.h>


class Portal
{
public:
	Portal();
	void render();

private:
	Model model;
	Vector3f pos;
};

