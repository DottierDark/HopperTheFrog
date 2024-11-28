#include <Game Engine/Lighting/Lighting.hpp>


Lighting::Lighting() {
	// Initialize light properties
	lightPosition[0] = 0.0f; lightPosition[1] = 10.0f; lightPosition[2] = 0.0f; lightPosition[3] = 1.0f;
	ambientLight[0] = 0.2f; ambientLight[1] = 0.2f; ambientLight[2] = 0.2f; ambientLight[3] = 1.0f;
	diffuseLight[0] = 1.0f; diffuseLight[1] = 1.0f; diffuseLight[2] = 1.0f; diffuseLight[3] = 1.0f;
	specularLight[0] = 1.0f; specularLight[1] = 1.0f; specularLight[2] = 1.0f; specularLight[3] = 1.0f;
}

void Lighting::setupLighting() {
	glEnable(GL_LIGHTING);   // Enable lighting
	glEnable(GL_LIGHT0);     // Enable light source 0

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void Lighting::updateLighting(float timeOfDay) {
	// Simulate circular movement for light
	lightPosition[0] = cos(timeOfDay) * 10.0f;
	lightPosition[2] = sin(timeOfDay) * 10.0f;
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}