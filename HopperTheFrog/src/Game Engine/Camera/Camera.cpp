#include "Camera.hpp"

// Global variables
extern int windowHeight;
extern int windowWidth;


Camera::Camera() {
	eye = Vector3f(10.0f, 50.0f, -10.0f);   // Default third-person offset
	center = Vector3f(0.0f, 1.0f, 0.0f);    // Looking at the player
	up = Vector3f(0.0f, 1.0f, 0.0f);        // Up direction
	currentView = THIRD_PERSON;
	FOV = 60;
}

Camera::Camera(float eyeX, float eyeY, float eyeZ,
	float centerX, float centerY, float centerZ,
	float upX, float upY, float upZ) {
	eye = Vector3f(eyeX, eyeY, eyeZ);
	center = Vector3f(centerX, centerY, centerZ);
	up = Vector3f(upX, upY, upZ);
	currentView = THIRD_PERSON;
	FOV = 60;
}

void Camera::applyView() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(FOV, (float)windowWidth / (float)windowHeight, 0.1, 1000.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		eye.x, eye.y, eye.z,
		center.x, center.y, center.z,
		up.x, up.y, up.z
	);
}

void Camera::update(float playerX, float playerY, float playerZ, float playerRotY) {
	if (currentView == THIRD_PERSON) {
		// Position the camera behind and above the player
		eye = Vector3f(
			playerX + 10.0f,   // Offset backward (relative to X)
			playerY + 30.0f,                                     // Above the player
			playerZ + 20.0f // Behind the player (relative to Z)
		);

		// Look slightly ahead of the player
		center = Vector3f(
			playerX + 0.0f,  // Forward (relative to X)
			playerY + 0.0f,                                    // At player's height
			playerZ + 0.0f  // Forward (relative to Z)
		);

		FOV = 60;
	}
	else if (currentView == FIRST_PERSON) {
		// Position the camera at the player's head level
		eye = Vector3f(
			playerX + 0.0f,   // Offset backward (relative to X)
			playerY + 3.0f,                                     // Above the player
			playerZ + -10.0f // Behind the player (relative to Z)
		);

		// Look slightly ahead of the player
		center = Vector3f(
			playerX + 0.0f,  // Forward (relative to X)
			playerY + 3.0f,                                    // At player's height
			playerZ + -15.0f  // Forward (relative to Z)
		);

		FOV = 100;
	}
}

void Camera::toggleView() {
	if (currentView == FIRST_PERSON) {
		currentView = THIRD_PERSON;
	}
	else {
		currentView = FIRST_PERSON;
	}
}
