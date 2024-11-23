#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

void drawStreet() {
	std::cout << "Drawing Street..." << std::endl;
	// Add OpenGL code to render the street here
}