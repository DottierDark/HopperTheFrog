#include <Environment/Levels/Level2/Level2.h>

Level2::Level2() {
	std::cout << "Level1 created!" << std::endl;

	// Draw the lighting
	lighting.setupLighting();

	// Camera setup
	camera.setPosition(0.0f, 5.0f, 20.0f);
	camera.setTarget(0.0f, 0.0f, 0.0f);
}

void Level2::update(float deltaTime) {
	std::cout << "Updating Level1..." << std::endl;

	// Update the lighting
	lighting.updateLighting(deltaTime);

}


void Level2::render() {



}