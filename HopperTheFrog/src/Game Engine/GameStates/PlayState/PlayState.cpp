#include <Game Engine/GameStates/PlayState/PlayState.hpp>


PlayState::PlayState() {
	ground = Ground();

}

void PlayState::enter(const std::vector<std::string>& enterParams) {

	// Draw the lighting
	lighting.setupLighting();

	level1 = Level1();
	level2 = Level2();

	frog = Frog();
	camera = Camera();
	lighting = Lighting();

	currentLevel = 1;
}

void PlayState::update(float deltaTime) {

	if (currentLevel == 1) {
		level1.update(deltaTime);
	}
	else if (currentLevel == 2) {
		level2.update(deltaTime);
	}

	// Update the lighting
	lighting.updateLighting(deltaTime);

	// Update the frog
	frog.update(deltaTime);

	// Check if the frog has reached the portal
	if (currentLevel == 1) {
		if (frog.getX() > 10.0f && !level1Complete) {
			level1Complete = true;
			currentLevel = 2;
		}
	}
	else if (currentLevel == 2) {
		if (frog.getX() > 10.0f && !level2Complete) {
			level2Complete = true;
			currentLevel = 1;
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
			//case '1': {
			//	// Toggle between FPV and TPV
			//	camera.toggleView(frog.getX(), frog.getY(), frog.getZ(), frog.getRotationY());
			//	break;
			//}
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
}

void PlayState::exit() {
}


