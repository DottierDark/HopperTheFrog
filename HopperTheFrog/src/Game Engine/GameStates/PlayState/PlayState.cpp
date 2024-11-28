#include <Game Engine/GameStates/PlayState/PlayState.hpp>


PlayState::PlayState() {

}

void PlayState::enter(const std::vector<std::string>& enterParams) {
}

void PlayState::update(float deltaTime) {

	if (currentLevel == 1) {
		level1.update(deltaTime);
	}
	else if (currentLevel == 2) {
		level2.update(deltaTime);
	}
}


void PlayState::handleMouseClick(int button, int state, int x, int y) {
}

void PlayState::handleKeyPress(unsigned char key, int x, int y) {
}

void PlayState::render() {
	if (currentLevel == 1) {
		level1.render();
	}
	else if (currentLevel == 2) {
		level2.render();
	}
}

void PlayState::exit() {
}


