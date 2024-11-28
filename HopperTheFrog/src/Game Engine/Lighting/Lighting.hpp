#pragma once

#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

class Lighting {
public:
	Lighting();
	void setupLighting();
	void updateLighting(float timeOfDay);

private:
	float lightPosition[4]; // Light position (x, y, z, w)
	float ambientLight[4];  // Ambient light intensity
	float diffuseLight[4];  // Diffuse light intensity
	float specularLight[4]; // Specular light intensity
};