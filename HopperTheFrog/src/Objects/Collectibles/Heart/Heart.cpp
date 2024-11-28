#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

void drawHeart() {
	std::cout << "Drawing Heart..." << std::endl;
	// Add OpenGL code for the heart collectible here
}