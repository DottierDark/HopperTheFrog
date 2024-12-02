#pragma once
#include <Game Engine/GameStates/State.hpp>
#include <Game Engine/GameStates/MenuState/MenuState.hpp>
#include <Game Engine/GameStates/PlayState/PlayState.hpp>
#include <Game Engine/GameStates/GameWinState/GameWinState.hpp>
#include <Game Engine/GameStates/StateManager.hpp>


#include <Objects/Player/Frog.hpp>
#include <Environment/Levels/Level1/Level1.h>
#include <Environment/Levels/Level2/Level2.h>




extern int windowHeight;
extern int windowWidth;
extern StateManager gStateMachine;


class GameWinState : public State {

public:
	GameWinState();
	void enter(const std::vector<std::string>& enterParams) override;
	void update(float deltaTime) override;
	void handleMouseClick(int button, int state, int x, int y) override;
	void handleKeyPress(unsigned char key, int x, int y) override;
	void handleKeyRelease(unsigned char key, int x, int y) override;
	void render() override;
	void exit() override;
	void renderStrokeText(const char* text, int x, int y, float scale);

private:
	int playerScore = 0;
};

