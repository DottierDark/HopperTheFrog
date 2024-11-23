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
		GLfloat lightPos[] = { 0.0f, 10.0f, 10.0f, 1.0f }; // Light positioned above and slightly behind the camera
		glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

		GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f }; // Add ambient light
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);

		GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8f, 1.0f }; // Adjust diffuse intensity
		glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);

		// Set the light color
		GLfloat lightColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);

		GLfloat materialDiffuse[] = { 0.2f, 0.2f, 0.2f, 1.0f }; // Dark gray road material
		glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);

		GLfloat materialSpecular[] = { 0.5f, 0.5f, 0.5f, 1.0f }; // Add some specular reflection
		glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);

		GLfloat materialShininess[] = { 50.0f }; // Shininess factor
		glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);
	}
};