#pragma once

#include <iostream>

#include <Objects/Obstacles/Car/Car.hpp>
#include <Objects/Collectibles/Coin/Coin.hpp>
#include <Objects//Targets/Portal/Portal.hpp>


#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#include <Utils/Textures/Model_3DS.h>
#include <Utils/Textures/GLTexture.h>
#include <Game Engine/Camera/Camera.hpp>
#include <Game Engine/Lighting/Lighting.hpp>
#else

#include <vector>

#include <Utils/Textures/Model_3DS.h>
#include  <Utils/Textures/GLTexture.h>



#include <GL/glut.h>   // Include GLUT for other platforms
#endif




class Level1 {
public:
	Level1();
	void update(float deltaTime);
	void render();


private:

	// Add Level1 attributes


	Model_3DS street;


	std::vector<Car> cars;
	std::vector<Coin> coins;
	Portal portal;

};

