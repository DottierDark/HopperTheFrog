#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

void setupCamera() {
	std::cout << "Setting up Camera..." << std::endl;
	// Add OpenGL code to configure the camera here
}