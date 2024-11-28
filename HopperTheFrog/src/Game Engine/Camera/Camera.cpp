#include "Camera.hpp"

Camera::Camera() : posX(0.0f), posY(5.0f), posZ(20.0f),
targetX(0.0f), targetY(0.0f), targetZ(0.0f),
upX(0.0f), upY(1.0f), upZ(0.0f) {}

void Camera::setPosition(float x, float y, float z) {
	posX = x; posY = y; posZ = z;
}

void Camera::setTarget(float x, float y, float z) {
	targetX = x; targetY = y; targetZ = z;
}

void Camera::setUpVector(float x, float y, float z) {
	upX = x; upY = y; upZ = z;
}

void Camera::applyView() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(posX, posY, posZ, targetX, targetY, targetZ, upX, upY, upZ);
}
