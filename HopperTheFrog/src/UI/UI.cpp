#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

void drawUI() {
	std::cout << "Drawing UI..." << std::endl;
	// Add OpenGL code for rendering UI elements
}