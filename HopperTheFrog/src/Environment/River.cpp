#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

void drawRiver() {
	std::cout << "Drawing River..." << std::endl;
	// Add OpenGL code to render the river here
}