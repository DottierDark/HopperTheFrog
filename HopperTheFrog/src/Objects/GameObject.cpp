#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

void drawGameObject() {
	std::cout << "Drawing GameObject..." << std::endl;
	// Add OpenGL code for a generic object here
}