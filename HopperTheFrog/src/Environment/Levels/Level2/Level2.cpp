#include "Level2.h"

Level2::Level2() {

	lilyPadSpacing = 50.0f;
	totalLilyPads = 6;
	// Initialize rivers
	rivers.push_back(River(10.0f, 0.0f, -60.0f));
	rivers.push_back(River(10.0f, 0.0f, 60.0f));

	// Initialize house
	house = House(0, 0, -120);

	// Spawn lily pads and hearts
	spawnLilyPads();
	spawnHearts();
}

void Level2::spawnLilyPads() {
	int padsPerRiver = totalLilyPads / 2; // Split equally between rivers
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
				if (abs(randomX - usedX) < lilyPadSpacing) {
					validPosition = false;
					break;
				}
			}
		} while (!validPosition);

		usedPositionsRiver1.push_back(randomX);
		lilyPads.push_back(LilyPad(randomX, 0.0f, -60.0f)); // River1
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
				if (abs(randomX - usedX) < lilyPadSpacing) {
					validPosition = false;
					break;
				}
			}
		} while (!validPosition);

		usedPositionsRiver2.push_back(randomX);
		lilyPads.push_back(LilyPad(randomX, 0.0f, 60.0f)); // River2
	}
}



void Level2::spawnHearts() {
	int heartsToSpawn = 5; // Number of hearts to spawn
	if (heartsToSpawn == 0) return;

	std::unordered_set<int> usedIndices;
	while (usedIndices.size() < heartsToSpawn) {
		int randomIndex = rand() % lilyPads.size();
		if (usedIndices.insert(randomIndex).second) { // Insert if not already used
			const auto& selectedLilyPad = lilyPads[randomIndex];
			hearts.push_back(Heart(selectedLilyPad.pos.x, selectedLilyPad.pos.y + 1.0f, selectedLilyPad.pos.z));
		}
	}
}



void Level2::update(float deltaTime) {
}

void Level2::render() {
	for (auto& river : rivers) river.render();
	for (auto& lilyPad : lilyPads) lilyPad.render();
	for (auto& heart : hearts) heart.render();
	house.render();
}