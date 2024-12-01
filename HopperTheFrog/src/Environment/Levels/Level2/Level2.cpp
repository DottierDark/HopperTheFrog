#include "Level2.h"

Level2::Level2() {
	// Initialize Level2 attributes
	// Create a house object
	house = House();
	// Add River objects to the rivers vector
	rivers.push_back(River(0.0f, 0.0f, 0.0f));
	rivers.push_back(River(0.0f, 0.0f, 0.0f));
	// Add LilyPad objects to the lilyPads vector
	lilyPads.push_back(LilyPad(0.0f, 0.0f, 0.0f));
	lilyPads.push_back(LilyPad(0.0f, 0.0f, 0.0f));
	// Add Heart objects to the hearts vector
	hearts.push_back(Heart(0.0f, 0.0f, 0.0f));
	hearts.push_back(Heart(0.0f, 0.0f, 0.0f));
}

void Level2::update(float deltaTime) {


}


void Level2::render() {

	// Render Level2 attributes
	// Render House object
	house.render();
	// Render River objects
	for (int i = 0; i < rivers.size(); i++) {
		rivers[i].render();
	}
	// Render LilyPad objects
	for (int i = 0; i < lilyPads.size(); i++) {
		lilyPads[i].render();
	}
	// Render Heart objects
	for (int i = 0; i < hearts.size(); i++) {
		hearts[i].render();
	}

}