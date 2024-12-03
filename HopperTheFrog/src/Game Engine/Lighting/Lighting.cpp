#include "Lighting.hpp"


Lighting::Lighting() {
	// Initialize light position and properties
	lightPosition[0] = 300.0f; // X
	lightPosition[1] = 200.0f; // Y
	lightPosition[2] = 0.0f; // Z
	lightPosition[3] = 1.0f; // W (directional light if 0, positional light if 1)

	ambientLight[0] = 0.2f; ambientLight[1] = 0.2f; ambientLight[2] = 0.2f; ambientLight[3] = 1.0f;
	diffuseLight[0] = 1.0f; diffuseLight[1] = 1.0f; diffuseLight[2] = 1.0f; diffuseLight[3] = 1.0f;
	specularLight[0] = 1.0f; specularLight[1] = 1.0f; specularLight[2] = 1.0f; specularLight[3] = 1.0f;


	glEnable(GL_LIGHT0); // Enable the first light
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);


	// Load the sun and moon models
	sun.Load("assets/models/sun/sun.3ds");
	sun.scale = 10.0f;
	moon.Load("assets/models/Moon/moon.3ds");

	moon.scale = 5.0f;

	// Initialize time of day
	timeOfDay = 0.0f;
}

void Lighting::updateLighting(float deltatime) {
	// Update time of day

	timeOfDay += deltatime;
	// Simulate circular movement around the Z-axis
	lightPosition[0] = cos(timeOfDay) * 250.0f; // X-coordinate
	lightPosition[1] = sin(timeOfDay) * 100.0f; // Y-coordinate
	lightPosition[2] = 0.0f;                   // Z-coordinate remains fixed

	// Update light position
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	// Adjust sky color and light properties for day-night cycle
	if (lightPosition[1] < 0.0f) { // Light is below the horizon
		glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark sky for night

		// Dim ambient, diffuse, and specular light at night
		ambientLight[0] = 0.1f; ambientLight[1] = 0.1f; ambientLight[2] = 0.1f;
		GLfloat nightIntensity = 0.2f;
		diffuseLight[0] = nightIntensity;
		diffuseLight[1] = nightIntensity;
		diffuseLight[2] = nightIntensity;
		specularLight[0] = nightIntensity;
		specularLight[1] = nightIntensity;
		specularLight[2] = nightIntensity;

		sun.visible = false;
		moon.visible = true;
	}
	else { // Light is above the horizon
		glClearColor(0.5f, 0.7f, 1.0f, 1.0f); // Bright sky for day

		// Restore normal ambient, diffuse, and specular light during the day
		ambientLight[0] = 0.2f; ambientLight[1] = 0.2f; ambientLight[2] = 0.2f;
		GLfloat dayDiffuseIntensity = std::fmax(0.0f, lightPosition[1] / 10.0f);
		diffuseLight[0] = dayDiffuseIntensity;
		diffuseLight[1] = dayDiffuseIntensity;
		diffuseLight[2] = dayDiffuseIntensity;

		GLfloat daySpecularIntensity = std::fmax(0.0f, lightPosition[1] / 5.0f); // Stronger specular highlights
		specularLight[0] = daySpecularIntensity;
		specularLight[1] = daySpecularIntensity;
		specularLight[2] = daySpecularIntensity;

		sun.visible = true;
		moon.visible = false;
	}

	// Apply updated lighting
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
}


void Lighting::render() {
	glPushMatrix();
	glTranslatef(lightPosition[0], lightPosition[1], lightPosition[2]);
	sun.Draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-lightPosition[0], -lightPosition[1], lightPosition[2]);
	moon.Draw();
	glPopMatrix();
}