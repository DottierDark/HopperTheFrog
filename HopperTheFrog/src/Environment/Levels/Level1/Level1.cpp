#include <Environment/Levels/Level1/Level1.h>
#include <Utils/TextureUtils.h>
extern GLuint streetTexture;
#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

void Level1::drawStreet() {
    std::cout << "Drawing a realistic street with texture..." << std::endl;

    // Enable texture mapping
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, streetTexture); // Bind the street texture
    glGenerateMipmap(GL_TEXTURE_2D); // Generate mipmaps for the texture

    // Draw the textured road
    glColor3f(1.0f, 1.0f, 1.0f); // Ensure the texture's color is unmodified
    glBegin(GL_QUADS);

    // Map the texture to the quad
    // Left half of the road (two lanes)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-8.0f, 0.0f, -50.0f);
    glTexCoord2f(2.0f, 0.0f); glVertex3f(0.0f, 0.0f, -50.0f);
    glTexCoord2f(2.0f, 1.0f); glVertex3f(0.0f, 0.0f, 10.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-8.0f, 0.0f, 10.0f);

    // Right half of the road (two lanes)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, -50.0f);
    glTexCoord2f(2.0f, 0.0f); glVertex3f(8.0f, 0.0f, -50.0f);
    glTexCoord2f(2.0f, 1.0f); glVertex3f(8.0f, 0.0f, 10.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 10.0f);

    glEnd();

    // Disable texture mapping
    glDisable(GL_TEXTURE_2D);

    // Draw sidewalks on both sides (lighter gray)
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
        // Left sidewalk
        glVertex3f(-10.0f, 0.0f, -50.0f);
        glVertex3f(-8.0f, 0.0f, -50.0f);
        glVertex3f(-8.0f, 0.0f, 10.0f);
        glVertex3f(-10.0f, 0.0f, 10.0f);

        // Right sidewalk
        glVertex3f(8.0f, 0.0f, -50.0f);
        glVertex3f(10.0f, 0.0f, -50.0f);
        glVertex3f(10.0f, 0.0f, 10.0f);
        glVertex3f(8.0f, 0.0f, 10.0f);
    glEnd();


    // Add cylindrical curbs
    GLUquadric* quad = gluNewQuadric(); // Create a new quadric object for cylinders

    // Left curb
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f); // Dark gray for curbs
    glTranslatef(-10.5f, 0.5f, -50.0f); // Position the cylinder (start further back)
    glRotatef(90, 0.0f, 0.0f, 1.0f);    // Rotate to align along the Z-axis
    gluCylinder(quad, 0.5f, 0.5f, 100.0f, 32, 32); // Increase height (100 units)
    glPopMatrix();

    // Right curb
    glPushMatrix();
    glColor3f(0.3f, 0.3f, 0.3f); // Dark gray for curbs
    glTranslatef(10.5f, 0.5f, -50.0f); // Position the cylinder (start further back)
    glRotatef(90, 0.0f, 0.0f, 1.0f);    // Rotate to align along the Z-axis
    gluCylinder(quad, 0.5f, 0.5f, 100.0f, 32, 32); // Increase height (100 units)
    glPopMatrix();

    gluDeleteQuadric(quad); // Clean up the quadric object
}