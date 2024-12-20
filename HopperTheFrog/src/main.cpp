#include <iostream>
#include <string>

#include "Game Engine/GameStates/PlayState/PlayState.hpp"

#include "Utils/SoundManager/SoundManager.hpp"
#include "Game Engine/GameStates/StateManager.hpp"
#include "Game Engine/GameStates/MenuState/MenuState.hpp"

#include "Game Engine/GameStates/GameWinState/GameWinState.hpp"
#include "Game Engine/GameStates/GameLoseState/GameLoseState.hpp"

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else

#include <GL/glut.h>   // Include GLUT for other platforms
#endif


// Global variables
int windowHeight = 1080;
int windowWidth = 1920;

int groundSize = 150;


//time between frames
float lastTime = 0.0f;


// State manager
StateManager gStateMachine({
	{"menu", []() -> State* { return new MenuState(); }},
	{"play", []() -> State* { return new PlayState(); }},
	{"gameover", []() -> State* { return new GameWinState(); }},
	{"gameoverlose", []() -> State* { return new GameLoseState(); }}
	});

SoundManager soundManager;

// Display callback for rendering the scene
void Render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear screen and depth buffer

	gStateMachine.render();

	glutSwapBuffers(); // Swap the front and back frame buffers (double buffering)


}

void Update(int value) {

	// Calculate time passed between frames (deltaTime)
	float currentTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f; // Time in seconds
	float deltaTime = currentTime - lastTime;
	lastTime = currentTime;

	// Update the state machine
	gStateMachine.update(deltaTime);

	glutPostRedisplay();
	// Call the update function every 1/60 seconds
	glutTimerFunc(1000 / 60, Update, 0);
}

// Keyboard callback for handling player actions
void KeyBoardFunc(unsigned char key, int x, int y) {

	switch (key) {
	case 27: // Escape key
		exit(0);
		break;
	}
	// Call the playerAction function from the PlayState
	gStateMachine.handleKeyPress(key, x, y);
}

void KeyBoardUpFunc(unsigned char key, int x, int y) {
	// Call the playerAction function from the PlayState
	gStateMachine.handleKeyRelease(key, x, y);
}

// Mouse callback for handling mouse clicks
void MouseFunc(int button, int state, int x, int y) {
	// Call the handleMouseClick function from the PlayState
	gStateMachine.handleMouseClick(button, state, x, y);
}

//=======================================================================
// Material Configuration Function
//======================================================================
void InitMaterial()
{
	// Enable Material Tracking
	glEnable(GL_COLOR_MATERIAL);

	// Sich will be assigneet Material Properties whd by glColor
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	// Set Material's Specular Color
	// Will be applied to all objects
	GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

	// Set Material's Shine value (0->128)
	GLfloat shininess[] = { 96.0f };
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
}

//=======================================================================
// OpengGL Configuration Function
//=======================================================================
void myInit(void) {
	glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, windowWidth, windowHeight); // Ensure viewport matches window size
	glMatrixMode(GL_MODELVIEW);
}

//=======================================================================
// Reshape Function
//=======================================================================
void myReshape(int w, int h)
{
	if (h == 0) {
		h = 1;
	}

	windowWidth = w;
	windowHeight = h;

	// set the drawable region of the window
	glViewport(0, 0, w, h);
}

void initSounds() {
	// Path to the assets folder
	std::string assetsPath = "assets/sounds";
	soundManager.addSound("background", assetsPath + "/BackGround.wav");
	soundManager.addSound("CollectedItem", assetsPath + "/CollectedItem.wav");
	soundManager.addSound("LoseLife", assetsPath + "/LoseLife.wav");
	soundManager.addSound("EndOfEnvironment", assetsPath + "/EndOfEnvironment.wav");
	soundManager.addSound("GameWin", assetsPath + "/GameWin.wav");
	soundManager.addSound("GameLose", assetsPath + "/GameLose.wav");
	soundManager.addSound("MainMenu", assetsPath + "/MainMenu.wav");

}



// Main function
int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Single buffering, RGB mode, depth buffer
	glutInitWindowSize(windowWidth, windowHeight);                             // Set window size to 800x600
	glutInitWindowPosition(0, 0);                         // Position the window
	glutCreateWindow("HopperTheFrog");                        // Create the window with a title


	// Initialize OpenGL settings
	myInit();

	// Initialize the sound manager
	initSounds();



	gStateMachine.change("menu", {}); // Start the game with the menu state

	// Register display callback
	glutDisplayFunc(Render);

	// Register the update function

	glutTimerFunc(1000 / 60, Update, 0);

	// Register the keyboard function
	glutKeyboardFunc(KeyBoardFunc);

	// Register the keyboard up function
	glutKeyboardUpFunc(KeyBoardUpFunc);

	// Register the mouse function
	glutMouseFunc(MouseFunc);

	// Register the reshape function
	glutReshapeFunc(myReshape);

	// Enter the GLUT event loop
	glutMainLoop();

	return 0;
}