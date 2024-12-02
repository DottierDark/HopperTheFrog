#include <Environment/Levels/Level1/Level1.h>

Level1::Level1() {



	// Load the streets
	streets.push_back(Street(0.0f, 0.0f, -60.0f));
	streets.push_back(Street(0.0f, 0.0f, 60.0f));


	// Load the portal
	portal = Portal(0, 0, -120);

	// Set the spawn rates
	obstacleSpawnRate = 2.0f;
	obstacleSpawnRate2 = 1.5f;

	for (int i = 0; i < 3; i++) {
		spawnCoin();
	}
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

void Level1::spawnCoin() {
	float x = static_cast<float>(rand() % 200 - 100); // Random x
	float z = (rand() % 2 == 0) ? 60.0f : -60.0f; // Random z
	coins.push_back(Coin(x, 3, z));
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