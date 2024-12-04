#include <Game Engine/GameStates/PlayState/PlayState.hpp>


extern int windowHeight;
extern int windowWidth;

extern int groundSize;

extern StateManager gStateMachine;

PlayState::PlayState() {
	ground = Ground();
	frog = Frog(0, 5, 142);
	camera = Camera();
	lighting = Lighting();
	currentLevel = 1;
	level1Complete = false;
	level2Complete = false;


}

void PlayState::enter(const std::vector<std::string>& enterParams) {

	soundManager.playBackgroundMusic("background", true);

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
			soundManager.stopBackgroundMusic();
			soundManager.playSound("EndOfEnvironment");
			soundManager.playBackgroundMusic("background", true);
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
					soundManager.stopBackgroundMusic();
					soundManager.playSound("LoseLife");
					soundManager.playBackgroundMusic("background", true);
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
				soundManager.stopBackgroundMusic();
				soundManager.playSound("CollectedItem");
				soundManager.playBackgroundMusic("background", true);
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

		if ((frog.getZ() <= 70 && frog.getZ() >= 50) || (frog.getZ() <= -50 && frog.getZ() >= -70)) {
			bool isOnLilyPad = false;
			for (auto& lilyPad : level2.lilyPads) {
				if (frog.hasCollided(lilyPad.pos, 30)) { // Adjust collision radius for lily pads
					isOnLilyPad = true;
					break;
				}
			}

			if (!isOnLilyPad) {
				soundManager.stopBackgroundMusic();	
				soundManager.playSound("LoseLife");
				soundManager.playBackgroundMusic("background", true);
				frog.takeDamage();
				frog.resetPosition(); // Reset the frog's position
				if (frog.getLives() == 0) {
					gStateMachine.change("gameoverlose", { std::to_string(frog.getScore()) });
				}
			}
		}

		for (auto it = level2.hearts.begin(); it != level2.hearts.end();) {
			// Check if the coin has been collected
			if (frog.hasCollided(it->pos, 10)) { // Adjust collision radius as needed
				// Handle coin collection (e.g., increase score, etc.)
				soundManager.stopBackgroundMusic();
				soundManager.playSound("CollectedItem");
				soundManager.playBackgroundMusic("background", true);
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
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			camera.toggleView(); break; // Toggle FPV/TPV
		}
	default:
		break;
	}
}

void PlayState::handleKeyPress(unsigned char key, int x, int y) {
	switch (key) {
	case 'w': {
		frog.moveForward();
		break;
	}
	case 's': {
		frog.moveBackward();
		break;
	}
	case 'a': {
		frog.moveLeft();
		break;
	}
	case 'd': {
		frog.moveRight();
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

	// Draw the lighting
	lighting.render();


}

void PlayState::exit() {
}


