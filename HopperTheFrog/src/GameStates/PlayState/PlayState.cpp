#include <GameStates/PlayState/PlayState.hpp>


PlayState::PlayState() {
}

void PlayState::enter(const std::vector<std::string>& enterParams) {
}

void PlayState::update(float deltaTime) {
}


void PlayState::handleMouseClick(int button, int state, int x, int y) {
}

void PlayState::handleKeyPress(unsigned char key, int x, int y) {
}

void PlayState::render() {
    level1.drawStreet(); // This should draw the street
}

void PlayState::exit() {
}


