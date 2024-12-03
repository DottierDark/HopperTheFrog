#include "Ground.h"


extern int groundSize;


Ground::Ground() {
	texture.Load("assets/textures/ground.bmp"); // Load the ground texture


	frontWall = Wall(0.0f, 0.0f, -groundSize);
	backWall = Wall(0.0f, 0.0f, groundSize);

	// because we did the rotate first the x and z are switched for the walls
	leftWallBetweenRoads = Wall(0, 0.0f, -groundSize);
	rightWallBetweenRoads = Wall(0, 0.0f, groundSize);

	leftWallBeforeRoad1 = Wall(-groundSize * 1.5, 0.0f, -groundSize);
	rightWallBeforeRoad1 = Wall(-groundSize * 1.5, 0.0f, groundSize);

	leftWallAfterRoad2 = Wall(groundSize * 1.5, 0.0f, -groundSize);
	rightWallAfterRoad2 = Wall(groundSize * 1.5, 0.0f, groundSize);


}

Ground::Ground(const char* textureFile) {
	texture.Load((char*)textureFile); // Load the ground texture

	frontWall = Wall(0.0f, 0.0f, -groundSize);
	backWall = Wall(0.0f, 0.0f, groundSize);

	leftWallBetweenRoads = Wall(0, 0.0f, -groundSize);
	rightWallBetweenRoads = Wall(0, 0.0f, groundSize);

	leftWallBeforeRoad1 = Wall(-groundSize, 0.0f, -groundSize);
	rightWallBeforeRoad1 = Wall(groundSize, 0.0f, groundSize);

	leftWallAfterRoad2 = Wall(-groundSize, 0.0f, -groundSize);
	rightWallAfterRoad2 = Wall(groundSize, 0.0f, groundSize);

}

void Ground::render() {
	// Render the ground
	glPushMatrix();
	texture.Use(); // Bind the texture
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-groundSize, 0.0f, -groundSize);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(groundSize, 0.0f, -groundSize);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(groundSize, 0.0f, groundSize);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-groundSize, 0.0f, groundSize);
	glEnd();
	glPopMatrix();

	// Render the walls
	glPushMatrix();
	glScalef(2.2f, 1.0f, 1.0f);
	frontWall.render();

	glPopMatrix();

	glPushMatrix();
	glScalef(2.2f, 1.0f, 1.0f);
	backWall.render();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(0.6f, 1.0f, 1.0f);
	leftWallBetweenRoads.render();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(0.6f, 1.0f, 1.0f);
	rightWallBetweenRoads.render();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(0.5f, 1.0f, 1.0f);
	leftWallBeforeRoad1.render();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(0.5f, 1.0f, 1.0f);
	rightWallBeforeRoad1.render();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(0.5f, 1.0f, 1.0f);
	leftWallAfterRoad2.render();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(0.5f, 1.0f, 1.0f);
	rightWallAfterRoad2.render();
	glPopMatrix();

}
