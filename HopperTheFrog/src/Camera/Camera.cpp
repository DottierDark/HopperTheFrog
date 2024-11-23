#include <Camera/Camera.hpp>


Camera::Camera() {
}

Camera::~Camera() {
}

void Camera::setupCamera() {
	glMatrixMode(GL_PROJECTION); // Set the matrix mode to projection
	glLoadIdentity();            // Load the identity matrix

	// Set the perspective of the camera
	gluPerspective(45.0f, (GLfloat)windowWidth / (GLfloat)windowHeight, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW); // Set the matrix mode to modelview
	glLoadIdentity();           // Load the identity matrix

	// Set the camera position and orientation
	gluLookAt(0.0f, 0.0f, 5.0f, // Eye position
		0.0f, 0.0f, 0.0f, // Look-at position
		0.0f, 1.0f, 0.0f); // Up direction
}