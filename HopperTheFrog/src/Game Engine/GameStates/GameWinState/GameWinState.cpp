#include "GameWinState.hpp"

GameWinState::GameWinState() {
}

void GameWinState::enter(const std::vector<std::string>& enterParams) {
	// Any initialization required when entering this state
	if (!enterParams.empty()) {
		playerScore = std::stoi(enterParams[0]);
	}
}

void GameWinState::update(float deltaTime) {
	// Any per-frame updates (not needed for static Game Win screen)
}

void GameWinState::handleMouseClick(int button, int state, int x, int y) {
	// Mouse input handling (not used in this example)
}

void GameWinState::handleKeyPress(unsigned char key, int x, int y) {
	switch (key) {
	case 'r': // Restart game
	case 'R': // Allow uppercase
		gStateMachine.change("play", {});
		break;
	case 'q': // Quit game
		std::exit(0);
		break;
	default:
		break;
	}
}

void GameWinState::handleKeyRelease(unsigned char key, int x, int y) {
	// Not used in this example
}

void GameWinState::render() {


	// Save the current OpenGL state
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	// Set up the 2D rendering environment
	glDisable(GL_LIGHTING); // Disable lighting for 2D rendering
	glDisable(GL_DEPTH_TEST); // Disable depth test for HUD
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, windowWidth, 0, windowHeight);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	// Clear the screen
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Dark background
	glClear(GL_COLOR_BUFFER_BIT); // Clear screen and depth buffer

	// Render "Game Win" text with stroke font

	glColor3f(0.0f, 0.5f, 1.0f); // Light blue for an encouraging message
	renderStrokeText("YOU WIN!", windowWidth / 2, windowHeight / 2 + 120, 0.9f);

	// Render "Restart" and "Quit" options with stroke font
	glColor3f(1.0f, 1.0f, 1.0f); // White color
	renderStrokeText("Press R to Restart!", windowWidth / 2, windowHeight / 2 + 40, 0.4f);
	renderStrokeText("Press Q to Quit :)", windowWidth / 2, windowHeight / 2 - 20, 0.4f);

	glColor3f(0.0f, 1.0f, 0.0f); // Green color
	renderStrokeText("Victory is Yours!", windowWidth / 2, windowHeight / 2 - 120, 0.2f);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	glDisable(GL_BLEND); // Disable blending
	glEnable(GL_DEPTH_TEST); // Re-enable depth test
	glEnable(GL_LIGHTING); // Re-enable lighting

	// Restore the OpenGL state
	glPopAttrib();
}

void GameWinState::exit() {
	// Any cleanup required when exiting this state
}

// Helper function to render stroke text (scalable and center-aligned)
void GameWinState::renderStrokeText(const char* text, int x, int y, float scale) {
	// Calculate the width of the text for centering
	float textWidth = 0.0f;
	for (const char* c = text; *c != '\0'; c++) {
		textWidth += glutStrokeWidth(GLUT_STROKE_ROMAN, *c);
	}

	// Adjust x to center-align the text
	float adjustedX = x - (textWidth * scale) / 2.0f;

	// Render the text
	glPushMatrix();
	glTranslatef(adjustedX, y, 0); // Move to position
	glScalef(scale, scale, scale); // Scale the text
	for (const char* c = text; *c != '\0'; c++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}
	glPopMatrix();
}