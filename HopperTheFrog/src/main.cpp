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
int windowHeight = 600;
int windowWidth = 800;


//time between frames
float lastTime = 0.0f;


// State manager
StateManager gStateMachine({
	{"menu", []() -> State* { return new MenuState(); }},
	{"play", []() -> State* { return new PlayState(); }},
	{"gameover", []() -> State* { return new GameWinState(); }},
	{"gameoverlose", []() -> State* { return new GameLoseState(); }}
	});

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
	gluPerspective(45.0, 800.0 / 600.0, 1.0, 100.0);
	glViewport(0, 0, 800, 600); // Ensure viewport matches window size
	glMatrixMode(GL_MODELVIEW);
}



// Main function
int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Single buffering, RGB mode, depth buffer
	glutInitWindowSize(windowWidth, windowHeight);                             // Set window size to 800x600
	glutInitWindowPosition(100, 100);                         // Position the window
	glutCreateWindow("HopperTheFrog");                        // Create the window with a title


	// Initialize OpenGL settings
	myInit();



	gStateMachine.change("play", {}); // Start the game with the menu state

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



	// Enter the GLUT event loop
	glutMainLoop();

	return 0;
}