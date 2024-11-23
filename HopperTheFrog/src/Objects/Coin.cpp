#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

void drawCoin() {
	std::cout << "Drawing Coin..." << std::endl;
	// Add OpenGL code for the coin collectible here
}