#include <Camera/Camera.hpp>

Camera::Camera() {
}

Camera::~Camera() {
}

void Camera::setupCamera() {
	glMatrixMode(GL_PROJECTION); // Set the matrix mode to projection
	glLoadIdentity();            // Load the identity matrix

	// Set a perspective projection with a wider view angle
	gluPerspective(60.0f, (GLfloat)windowWidth / (GLfloat)windowHeight, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW); // Set the matrix mode to modelview
	glLoadIdentity();           // Load the identity matrix

	// Position the camera at an angle for a 3D perspective
	gluLookAt(10.0f, 8.0f, 20.0f,  // Eye position (move up and back)
              0.0f, 0.0f, 0.0f,    // Look-at position (focus on the model's origin)
              0.0f, 1.0f, 0.0f);   // Up direction
}