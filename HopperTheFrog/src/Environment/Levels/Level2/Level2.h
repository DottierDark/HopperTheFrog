#pragma once

#include <vector>

#include <Objects/Targets/House/House.hpp>
#include <Objects/Obstacles/River/River.hpp>
#include <Objects/Collectibles/Heart/Heart.hpp>
#include <Objects/Platform/LilyPad.h>

#include <unordered_set>  // For std::unordered_set
#include <cstdlib>        // For rand()
#include <ctime>          // For seeding random number generator (optional)

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

	std::vector<River> rivers;
	std::vector<LilyPad> lilyPads;
	std::vector<Heart> hearts;
	House house;

private:
	int totalLilyPads; // Total number of lily pads to spawn
	float lilyPadSpacing; // Distance between lily pads

	void spawnLilyPads();
	void spawnHearts();
};


