#include <Environment/Levels/Level1/Level1.h>

Level1::Level1() {

	// Load the street model
	street.loadModel("assets/models/street.3ds");

	// Load the ground texture


	// Load the portal
	portal = Portal();


	// Load the cars
	cars.push_back(Car(0.0f, 0.0f, 0.0f, 1.0f));

	// Load the coins

	coins.push_back(Coin(0.0f, 0.0f, 0.0f));

}

void Level1::update(float deltaTime) {

}



void Level1::render() {



	// Draw the street
	street.render();

	// Draw the cars
	for (int i = 0; i < cars.size(); i++) {
		cars[i].render();
	}

	// Draw the coins
	for (int i = 0; i < coins.size(); i++) {
		coins[i].render();
	}

	// Draw the portal

	portal.render();



}