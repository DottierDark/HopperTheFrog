#pragma once

#include <iostream>
#include <cmath>
#include <Utils/3DModel/Model_3DS.h>
#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

class Lighting {
public:
	Lighting();
	void updateLighting(float deltatime);
	void render();

private:
	Model_3DS sun;
	Model_3DS moon;

	float timeOfDay;        // Time of day (0.0 to 2*PI)
	float lightPosition[4]; // Light position (x, y, z, w)
	float ambientLight[4];  // Ambient light intensity
	float diffuseLight[4];  // Diffuse light intensity
	float specularLight[4]; // Specular light intensity
};