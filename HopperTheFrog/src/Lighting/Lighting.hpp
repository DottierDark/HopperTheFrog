#pragma once

#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

class Lighting {
public:
	// Function to set up the lighting
	static void setupLighting() {
		std::cout << "Setting up Lighting..." << std::endl;
		glEnable(GL_LIGHTING); // Enable lighting calculations
		glEnable(GL_LIGHT0);   // Enable a single light source
		glEnable(GL_COLOR_MATERIAL); // Enable color tracking

		// Set the light position
		GLfloat lightPos[] = { 0.0f, 0.0f, 1.0f, 0.0f };
		glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

		// Set the light color
		GLfloat lightColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	}
};