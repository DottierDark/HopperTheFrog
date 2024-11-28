#include <Environment/Levels/Level1/Level1.h>

Level1::Level1() {
	std::cout << "Level1 created!" << std::endl;

	// Draw the lighting
	lighting.setupLighting();

	// Load the assets
	LoadAssets();

	// Camera setup
	camera.setPosition(0.0f, 5.0f, 20.0f);
	camera.setTarget(0.0f, 0.0f, 0.0f);
}

void Level1::update(float deltaTime) {
	std::cout << "Updating Level1..." << std::endl;

	// Update the lighting
	lighting.updateLighting(deltaTime);

}

//=======================================================================
// Assets Loading Function
//=======================================================================
void Level1::LoadAssets()
{
	// Loading Model files
	street.Load("assets/models/street.3ds");

	// Loading texture files
	tex_ground.Load("assets/textures/Ground-Textures/ground.bmp");
}

//=======================================================================
// Render Ground Function
//=======================================================================
void Level1::RenderGround()
{
	glDisable(GL_LIGHTING);	// Disable lighting 

	glColor3f(0.6, 0.6, 0.6);	// Dim the ground texture a bit

	glEnable(GL_TEXTURE_2D);	// Enable 2D texturing

	glBindTexture(GL_TEXTURE_2D, tex_ground.texture[0]);	// Bind the ground texture

	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);	// Set quad normal direction.
	glTexCoord2f(0, 0);		// Set tex coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
	glVertex3f(-20, 0, -20);
	glTexCoord2f(5, 0);
	glVertex3f(20, 0, -20);
	glTexCoord2f(5, 5);
	glVertex3f(20, 0, 20);
	glTexCoord2f(0, 5);
	glVertex3f(-20, 0, 20);
	glEnd();
	glPopMatrix();

	glEnable(GL_LIGHTING);	// Enable lighting again for other entites coming throung the pipeline.

	glColor3f(1, 1, 1);	// Set material back to white instead of grey used for the ground texture.
}


void Level1::render() {

	// Apply the camera view
	camera.applyView();

	// Draw the ground
	RenderGround();

	// Draw the street
	std::cout << "Drawing a realistic street from 3D model..." << std::endl;
	street.Draw();

	// Draw the buildings
	std::cout << "Drawing realistic buildings from 3D models..." << std::endl;

	// Draw the sky
	std::cout << "Drawing a realistic sky from 3D model..." << std::endl;

}