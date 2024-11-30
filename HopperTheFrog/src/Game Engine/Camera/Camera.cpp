#include "Camera.hpp"


Camera::Camera() {
	eye = Vector3f(-100.0f, 10.0f, 0.0f);   // Camera positioned directly above
	center = Vector3f(0.0f, 1.0f, 0.0f); // Looking at the origin
	up = Vector3f(0.0f, 1.0f, 0.0f);    // Up direction aligned with -Z
	currentView = THIRD_PERSON;
}

void Camera::applyView() {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 640 / 480, 0.001, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		eye.x, eye.y, eye.z,
		center.x, center.y, center.z,
		up.x, up.y, up.z
	);
}


Camera::Camera(float eyeX, float eyeY, float eyeZ,
	float centerX, float centerY, float centerZ,
	float upX, float upY, float upZ) {
	eye = Vector3f(eyeX, eyeY, eyeZ);
	center = Vector3f(centerX, centerY, centerZ);
	up = Vector3f(upX, upY, upZ);
	currentView = THIRD_PERSON;
}

void Camera::toggleView(float playerX, float playerY, float playerZ, float playerRotY) {
	// Define player's position as a vector
	Vector3f playerPosition(playerX, playerY, playerZ);

	if (currentView == FIRST_PERSON) {
		// Switch to third-person view
		currentView = THIRD_PERSON;
		eye = playerPosition;
		moveX(-sin(playerRotY * M_PI / 180.0f) * 10.0f); // Move backward
		moveZ(-cos(playerRotY * M_PI / 180.0f) * 10.0f); // Move to the right
		moveY(50.0f);                                     // Move upward
		center = playerPosition + Vector3f(0.0f, 1.0f, 0.0f); // Look at the frog

		// Set field of view
		setFOV(45.0f);
	}
	else {
		// Switch to first-person view
		currentView = FIRST_PERSON;
		eye = playerPosition + Vector3f(
			sin(playerRotY * M_PI / 180.0f) * 0.5f,
			1.5f,
			cos(playerRotY * M_PI / 180.0f) * 0.5f
		);
		center = playerPosition + Vector3f(
			sin(playerRotY * M_PI / 180.0f) * 10.0f,
			1.5f,
			cos(playerRotY * M_PI / 180.0f) * 10.0f
		);

		// Set field of view
		setFOV(60.0f);
	}
}

void Camera::moveX(float d) {
	Vector3f right = up.cross(center - eye).unit();
	eye = eye + right * d;
	center = center + right * d;
}

void Camera::moveY(float d) {
	Vector3f vertical = up.unit();
	eye = eye + vertical * d;
	center = center + vertical * d;
}

void Camera::moveZ(float d) {
	Vector3f forward = (center - eye).unit();
	eye = eye + forward * d;
	center = center + forward * d;
}

void Camera::setFOV(float fov) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, (float)windowWidth / (float)windowHeight, 0.1f, 1000.0f);
}
