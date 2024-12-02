#include <Game Engine/GameStates/PlayState/PlayState.hpp>


extern int windowHeight;
extern int windowWidth;

extern StateManager gStateMachine;

PlayState::PlayState() {
	ground = Ground();
	frog = Frog(0, 5, 142);
	camera = Camera();
	lighting = Lighting();
	currentLevel = 1;
	level1Complete = false;

}

void PlayState::enter(const std::vector<std::string>& enterParams) {

	// Draw the lighting
	lighting.setupLighting();

	level1 = Level1();
	level2 = Level2();

	frog = Frog(0, 5, 142);
	camera = Camera();
	lighting = Lighting();

	currentLevel = 1;
	level1Complete = false;
	level1Complete = false;

	// Set the camera view
	level1 = Level1();
	level2 = Level2();

}

void PlayState::update(float deltaTime) {



	// Update the lighting
	lighting.updateLighting(deltaTime);

	// Update the frog
	frog.update(deltaTime);
	camera.update(frog.getX(), frog.getY(), frog.getZ(),
		atan2(frog.getDirectionZ(), frog.getDirectionX()) * 180.0f / M_PI);

	// Check if the frog has reached the portal
	if (currentLevel == 1) {
		level1.update(deltaTime);

		if (frog.hasCollided(level1.portal.pos, 40)) {
			level1Complete = true;
			currentLevel = 2;
			frog.resetPosition();
		}

		for (auto it = level1.cars.begin(); it != level1.cars.end();) {
			it->update(deltaTime);

			// Check if the car reached the end of the street
			if (it->reachedEnd()) {
				it = level1.cars.erase(it); // Remove the car and update the iterator
			}
			else {
				// Check if the frog has collided with a car
				if (frog.hasCollided(it->pos, 25)) { // Adjust collision radius as needed
					// Handle frog-car collision (e.g., reset position, reduce life, etc.)
					frog.resetPosition();
					frog.takeDamage();
					if (frog.getLives() == 0) {
						// Game over lose
						gStateMachine.change("gameoverlose", { std::to_string(frog.getScore()) });
					}
				}

				++it; // Move to the next car
			}
		}
		for (auto it = level1.coins.begin(); it != level1.coins.end();) {
			it->update(deltaTime);

			// Check if the coin has been collected
			if (frog.hasCollided(it->pos, 10)) { // Adjust collision radius as needed
				// Handle coin collection (e.g., increase score, etc.)
				it = level1.coins.erase(it); // Remove the coin and update the iterator

				// Increase the player's score
				frog.addScore();
			}
			else {
				++it; // Move to the next coin
			}
		}
	}
	else if (currentLevel == 2) {
		for (auto it = level2.lilyPads.begin(); it != level2.lilyPads.end();) {
			// Check if the frog has collided with a car
			if (frog.hasCollided(it->pos, 15)) { // Adjust collision radius as needed
				// Handle frog-car collision (e.g., reset position, reduce life, etc.)
				frog.resetPosition();
				frog.takeDamage();
				if (frog.getLives() == 0) {
					// Game over lose
					gStateMachine.change("gameover", { std::to_string(frog.getScore()) });
				}
			}
			++it; // Move to the next car
		}

		for (auto it = level2.hearts.begin(); it != level2.hearts.end();) {
			// Check if the coin has been collected
			if (frog.hasCollided(it->pos, 10)) { // Adjust collision radius as needed
				// Handle coin collection (e.g., increase score, etc.)
				it = level2.hearts.erase(it); // Remove the coin and update the iterator
				// Increase the player's score
				frog.heal();
			}
			else {
				++it; // Move to the next coin
			}

		}

		if (frog.hasCollided(level2.house.pos, 30)) {
			// Game over win
			gStateMachine.change("gameover", { std::to_string(frog.getScore()) });
		}
	}


}


void PlayState::handleMouseClick(int button, int state, int x, int y) {
}

void PlayState::handleKeyPress(unsigned char key, int x, int y) {
	switch (key) {
	case 'w': {
		frog.moveForward();
		//// Move camera forward with the player
		//camera.moveZ(-frog.getSpeed() * deltaTime);
		break;
	}
	case 's': {
		frog.moveBackward();

		//// Move camera backward with the player
		//camera.moveZ(frog.getSpeed() * deltaTime);
		break;
	}
	case 'a': {
		frog.moveLeft();

		//// Move camera left with the player
		//camera.moveX(-frog.getSpeed() * deltaTime);
		break;
	}
	case 'd': {
		frog.moveRight();
		//// Move camera right with the player
		//camera.moveX(frog.getSpeed() * deltaTime);
		break;
	}
	case '1': {
		// Toggle between FPV and TPV
		camera.toggleView(); break; // Toggle FPV/TPV

	}
	}
}


void PlayState::handleKeyRelease(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
	case 's':
	case 'a':
	case 'd':
		frog.setMoving(false); // Stop movement when key is released
		break;
	}
}

void PlayState::render() {
	if (currentLevel == 1) {
		level1.render();
	}
	else if (currentLevel == 2) {
		level2.render();
	}

	// Apply the camera view
	camera.applyView();

	// Draw the ground
	ground.render();

	// Draw the frog
	frog.render();

	// Draw the score and lives
	frog.renderHUD();
}

void PlayState::exit() {
}


