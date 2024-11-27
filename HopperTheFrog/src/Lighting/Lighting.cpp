#include <Lighting/Lighting.hpp>
#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

void setupLighting() {
	std::cout << "Setting up Lighting..." << std::endl;

	// Enable lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); // Activate a single light source

	// Set light position
	GLfloat lightPos[] = {5.0f, 10.0f, 15.0f, 1.0f}; // Position in world space
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	// Set ambient light (soft global illumination)
	GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);

	// Set diffuse light (highlights surfaces facing the light)
	GLfloat diffuseLight[] = {0.8f, 0.8f, 0.8f, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);

	// Set specular light (shiny spots)
	GLfloat specularLight[] = {1.0f, 1.0f, 1.0f, 1.0f};
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);

	// Set material properties
	GLfloat materialSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
	glMateriali(GL_FRONT, GL_SHININESS, 64); // Shininess level
}