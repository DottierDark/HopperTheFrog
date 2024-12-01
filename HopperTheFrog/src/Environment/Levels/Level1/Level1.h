#pragma once

#include <iostream>

#include <vector>


#include <Environment/Street/Street.hpp>
#include <Objects/Targets/Portal/Portal.hpp>

//includes glut.h for macOS and other platforms
#include <Objects/Obstacles/Car/Car.hpp>
#include <Objects/Collectibles/Coin/Coin.hpp>

#include <Game Engine/Camera/Camera.hpp>
#include <Game Engine/Lighting/Lighting.hpp>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif




class Level1 {
public:
	Level1();
	void update(float deltaTime);
	void render();

	// Add Level1 attributes
	std::vector<Street> streets;
	std::vector<Car> cars;
	std::vector<Coin> coins;
	Portal portal;

};

