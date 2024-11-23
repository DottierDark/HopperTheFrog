#include <iostream>
#include <string>

#include <SoundManager/SoundManager.hpp>
#include <GameStates/StateManager.hpp>
#include <GameStates/MenuState/MenuState.hpp>
#include <GameStates/PlayState/PlayState.hpp>
#include <GameStates/GameWinState/GameWinState.hpp>
#include <GameStates/GameLoseState/GameLoseState.hpp>

#include <Camera/Camera.hpp>
#include <Lighting/Lighting.hpp>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif


// Global variables
int windowHeight = 600;
int windowWidth = 800;


Camera camera; // Camera object
Lighting lighting; // Lighting object


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

	// Call the drawing functions to render the scene
	lighting.setupLighting();  // Set up lighting
	camera.setupCamera();    // Configure the camera

	gStateMachine.render();


	glFlush();        // Ensure all OpenGL commands are executed
}

void Update(int value) {

	//get the delta time
	float dt = 1.0 / 60.0;


	// Update the state machine
	gStateMachine.update(dt);

	glutPostRedisplay();

	glutTimerFunc(1000 / 60, Update, 0);
}

// Keyboard callback for handling player actions
void KeyBoardFunc(unsigned char key, int x, int y) {
	// Call the playerAction function from the PlayState
	gStateMachine.handleKeyPress(key, x, y);
}

// Mouse callback for handling mouse clicks
void MouseFunc(int button, int state, int x, int y) {
	// Call the handleMouseClick function from the PlayState
	gStateMachine.handleMouseClick(button, state, x, y);
}

// OpenGL initialization function
void initOpenGL() {
	glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // Set background color to light blue (sky)
	glEnable(GL_DEPTH_TEST);             // Enable depth testing for 3D rendering
	glShadeModel(GL_SMOOTH);             // Use smooth shading
	std::cout << "OpenGL initialized successfully!" << std::endl;
}

// Main function
int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Single buffering, RGB mode, depth buffer
	glutInitWindowSize(windowWidth, windowHeight);                             // Set window size to 800x600
	glutInitWindowPosition(100, 100);                         // Position the window
	glutCreateWindow("HopperTheFrog");                        // Create the window with a title

	std::cout << "Game initialized!" << std::endl;

	// Initialize OpenGL settings
	initOpenGL();

	gStateMachine.change("menu", {}); // Start the game with the menu state

	// Register display callback
	glutDisplayFunc(Render);

	// Register the update function

	glutTimerFunc(1000 / 60, Update, 0);

	// Register the keyboard function
	glutKeyboardFunc(KeyBoardFunc);

	// Register the mouse function
	glutMouseFunc(MouseFunc);

	// Register the idle function





	// Enter the GLUT event loop
	glutMainLoop();

	return 0;
}