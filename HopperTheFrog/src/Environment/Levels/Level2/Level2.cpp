#include "Level2.h"

Level2::Level2() {
	// Load the streets
	rivers.push_back(River(0.0f, 0.0f, -60.0f));
	rivers.push_back(River(0.0f, 0.0f, 60.0f));


	// Load the portal
	house = House(0, 0, -120);

	for (int i = 0; i < 3; i++) {
		spawnCoin();
	}

	for (int i = 0; i < 3; i++) {
		spawnObstacle();
	}

	for (int i = 0; i < 3; i++) {
		spawnObstacle2();
	}
}

void Level2::spawnObstacle() {
	float x = static_cast<float>(rand() % 200 - 100); // Random x
	// Randomly pick either 60 or -60 for the z value
	float z = -60.0f;
	lilyPads.push_back(LilyPad(x, 0.0f, z)); // Example obstacle
}

void Level2::spawnObstacle2() {
	float x = static_cast<float>(rand() % 200 - 100); // Random x
	// Randomly pick either 60 or -60 for the z value
	float z = 60.0f;
	lilyPads.push_back(LilyPad(x, 0.0f, z)); // Example obstacle
}

void Level2::spawnCoin() {
	float x = static_cast<float>(rand() % 200 - 100); // Random x
	float z = (rand() % 2 == 0) ? 60.0f : -60.0f; // Random z
	hearts.push_back(Heart(x, 3, z));
}

void Level2::update(float deltaTime) {
}

void Level2::render() {
	for (auto& river : rivers) river.render();
	for (auto& lilyPad : lilyPads) lilyPad.render();
	for (auto& heart : hearts) heart.render();
	house.render();
}