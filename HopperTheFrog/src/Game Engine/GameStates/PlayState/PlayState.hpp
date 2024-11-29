#pragma once

#include <Game Engine/GameStates/State.hpp>
#include <Environment/Levels/Level1/Level1.h>
#include <Environment/Levels/Level2/Level2.h>

#include <Game Engine/Camera/Camera.hpp>
#include <Game Engine/Lighting/Lighting.hpp>

#include <Objects/Player/Frog.hpp>

#include <Environment/Ground/Ground.h>

#ifndef M_PI

#define M_PI 3.14159265358979323846
#endif // !M_PI


extern int windowHeight;
extern int windowWidth;

class PlayState : public State {
public:
	PlayState();
	void enter(const std::vector<std::string>& enterParams) override;
	void update(float deltaTime) override;
	void handleMouseClick(int button, int state, int x, int y) override;
	void handleKeyPress(unsigned char key, int x, int y) override;
	void handleKeyRelease(unsigned char key, int x, int y) override;
	void render() override;
	void exit() override;

private:
	Level1 level1; // Add Level1 instance
	Level2 level2;

	Frog frog;
	Camera camera;
	Lighting lighting;
	Ground ground;

	bool level1Complete = false;
	bool level2Complete = false;

	int currentLevel = 1;
};