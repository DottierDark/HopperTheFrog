#pragma once

#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

class Level1 {
public:
    void drawStreet(); // Declare the method to draw the street
};
