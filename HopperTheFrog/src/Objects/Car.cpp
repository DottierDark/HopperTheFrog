#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

void drawCar() {
	std::cout << "Drawing Car..." << std::endl;
	// Add OpenGL code for the car obstacle here
}