#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

void drawFrog() {
	std::cout << "Drawing Frog..." << std::endl;
	// Add OpenGL code to render the frog here
}