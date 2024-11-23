#include <iostream>
#include <string>

#include <SoundManager/SoundManager.h>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif


// Declare the functions from other files
void drawFrog();
void playerAction();
void drawStreet();

void drawRiver();
void drawGameObject();
void drawCar();
void drawCoin();
void drawHeart();
void setupCamera();
void setupLighting();
void drawUI();

// Display callback for rendering the scene
void displayCallback() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear screen and depth buffer

	// Call the drawing functions to render the scene
	setupLighting();  // Set up lighting
	setupCamera();    // Configure the camera

	drawStreet();     // Draw the street environment
	drawRiver();      // Draw the river environment
	drawCar();        // Draw car obstacles
	drawFrog();       // Draw the player (frog)
	drawCoin();       // Draw collectible coins
	drawHeart();      // Draw collectible hearts

	drawUI();         // Draw the UI (e.g., score, lives)

	glFlush();        // Ensure all OpenGL commands are executed
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
	glutInitWindowSize(800, 600);                             // Set window size to 800x600
	glutInitWindowPosition(100, 100);                         // Position the window
	glutCreateWindow("HopperTheFrog");                        // Create the window with a title

	std::cout << "Game initialized!" << std::endl;

	// Initialize OpenGL settings
	initOpenGL();

	// Register display callback
	glutDisplayFunc(displayCallback);

	// Enter the GLUT event loop
	glutMainLoop();

	return 0;
}