#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

void playerAction() {
	std::cout << "Player action triggered!" << std::endl;
	// Add player-related logic here
}