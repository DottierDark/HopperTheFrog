#pragma once
#include <Game Engine/GameStates/State.hpp>

extern int windowHeight;
extern int windowWidth;

class GameLoseState : public State {

public:
	GameLoseState();
	void enter(const std::vector<std::string>& enterParams) override;
	void update(float deltaTime) override;
	void handleMouseClick(int button, int state, int x, int y) override;
	void handleKeyPress(unsigned char key, int x, int y) override;
	void render() override;
	void exit() override;

private:

};

