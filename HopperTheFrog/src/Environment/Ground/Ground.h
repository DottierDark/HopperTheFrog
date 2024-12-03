#pragma once
#include <Utils/Textures/GLTexture.h>
#include <Objects/Wall/Wall.h>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

class Ground {
public:
	Ground();
	Ground(const char* textureFile);
	void render();

private:
	GLTexture texture; // Use the provided texture loader

	Wall frontWall;
	Wall backWall;


	Wall leftWallBetweenRoads;
	Wall leftWallBeforeRoad1;
	Wall leftWallAfterRoad2;

	Wall rightWallBetweenRoads;
	Wall rightWallBeforeRoad1;
	Wall rightWallAfterRoad2;


};

