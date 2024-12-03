#include "Level1.h"

Level1::Level1() {
	// Load the streets
	streets.push_back(Street(0.0f, 0.0f, -60.0f));
	streets.push_back(Street(0.0f, 0.0f, 60.0f));


	// Load the portal
	portal = Portal(0, 0, -120);

	// Set the spawn rates
	obstacleSpawnRate = 2.0f;
	obstacleSpawnRate2 = 1.5f;

	// Spawn coins
	spawnCoins();
}

void Level1::spawnObstacle() {
	float x = 200.0f; // Constant x value
	// Randomly pick either 60 or -60 for the z value
	float z = -60.0f;
	cars.push_back(Car(x, 0.0f, z)); // Example obstacle
}

void Level1::spawnObstacle2() {
	float x = 200.0f; // Constant x value
	// Randomly pick either 60 or -60 for the z value
	float z = 60.0f;
	cars.push_back(Car(x, 0.0f, z)); // Example obstacle
}

void Level1::spawnCoins() {
	int padsPerRiver = totalCoins / 2; // Split equally between rivers
	float riverWidth = 200.0f; // Adjust based on river size

	// Generate positions for River1
	std::vector<float> usedPositionsRiver1;
	for (int i = 0; i < padsPerRiver; ++i) {
		float randomX;
		bool validPosition;

		// Find a valid position with sufficient spacing
		do {
			randomX = static_cast<float>(rand() % static_cast<int>(riverWidth) - riverWidth / 2);
			validPosition = true;

			for (float usedX : usedPositionsRiver1) {
				if (abs(randomX - usedX) < coinSpacing) {
					validPosition = false;
					break;
				}
			}
		} while (!validPosition);

		usedPositionsRiver1.push_back(randomX);
		coins.push_back(Coin(randomX, 5.0f, -60.0f)); // River1
	}

	// Generate positions for River2
	std::vector<float> usedPositionsRiver2;
	for (int i = 0; i < padsPerRiver; ++i) {
		float randomX;
		bool validPosition;

		// Find a valid position with sufficient spacing
		do {
			randomX = static_cast<float>(rand() % static_cast<int>(riverWidth) - riverWidth / 2);
			validPosition = true;

			for (float usedX : usedPositionsRiver2) {
				if (abs(randomX - usedX) < coinSpacing) {
					validPosition = false;
					break;
				}
			}
		} while (!validPosition);

		usedPositionsRiver2.push_back(randomX);
		coins.push_back(Coin(randomX, 5.0f, 60.0f)); // River2
	}
}




void Level1::update(float deltaTime) {
	timeSinceLastObstacleStreet1 += deltaTime;
	timeSinceLastObstacleStreet2 += deltaTime;
	timeSinceLastCoin += deltaTime;

	if (timeSinceLastObstacleStreet1 >= obstacleSpawnRate) {
		spawnObstacle();

		timeSinceLastObstacleStreet1 = 0.0f;
	}

	if (timeSinceLastObstacleStreet2 >= obstacleSpawnRate2) {
		spawnObstacle2();
		timeSinceLastObstacleStreet2 = 0.0f;
	}


}



void Level1::render() {
	for (auto& street : streets) street.render();
	for (auto& car : cars) car.render();
	for (auto& coin : coins) coin.render();
	portal.render();
}