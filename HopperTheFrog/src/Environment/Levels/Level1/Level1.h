#pragma once

#include <iostream>

#include <vector>         // For std::vector (used for streets, cars, coins)
#include <unordered_set>  // For std::unordered_set (used for tracking used streets)
#include <cstdlib>        // For rand() and srand()
#include <ctime>          // For time() (optional, to seed the random generator)
#include <algorithm>      // For std::min (used to limit coin spawning to available streets)



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

private:
	int totalCoins = 6; // Configurable number of coins to spawn
	float coinSpacing = 20.0f; // Distance between coins
	void spawnCoins();

	// Add Level1 methods
	void spawnObstacle();
	void spawnObstacle2();
	float timeSinceLastObstacleStreet1 = 0.0f;
	float timeSinceLastObstacleStreet2 = 0.0f;
	float timeSinceLastCoin = 0.0f;
	float obstacleSpawnRate = 2.0f;
	float obstacleSpawnRate2 = 1.5f;
	float coinSpawnRate = 5.0f;

};

