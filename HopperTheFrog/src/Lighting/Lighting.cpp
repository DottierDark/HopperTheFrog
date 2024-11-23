#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

void setupLighting() {
	std::cout << "Setting up Lighting..." << std::endl;
	// Add OpenGL code to configure lighting here
}