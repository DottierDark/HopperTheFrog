#pragma once

#include <vector>

#include <Objects/Targets/House/House.hpp>
#include <Objects/Obstacles/River/River.hpp>
#include <Objects/Collectibles/Heart/Heart.hpp>
#include <Objects/Platform/LilyPad.h>

#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

class Level2 {
public:
	Level2();
	void update(float deltaTime);
	void render();

	// Add Level1 attributes
	std::vector<River> rivers;
	std::vector<LilyPad> lilyPads;
	std::vector<Heart> hearts;
	House house;

private:

	// Add Level1 methods
	void spawnObstacle();
	void spawnObstacle2();
	void spawnCoin();

};

