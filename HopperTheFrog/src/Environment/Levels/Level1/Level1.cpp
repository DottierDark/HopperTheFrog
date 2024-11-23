#include <Environment/Levels/Level1/Level1.h>
#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

void Level1::drawStreet() {
    std::cout << "Drawing a realistic street..." << std::endl;

    // Draw the main road (dark gray)
    glColor3f(0.2f, 0.2f, 0.2f); 
    glBegin(GL_QUADS);
        glVertex3f(-8.0f, 0.0f, -50.0f);
        glVertex3f(8.0f, 0.0f, -50.0f);
        glVertex3f(8.0f, 0.0f, 10.0f);
        glVertex3f(-8.0f, 0.0f, 10.0f);
    glEnd();

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

    // Draw dashed lane dividers
    for (float z = 9.5f; z > -50.0f; z -= 2.0f) {
        // Left lane divider
        glBegin(GL_QUADS);
            glVertex3f(-4.0f, 0.01f, z);
            glVertex3f(-3.8f, 0.01f, z);
            glVertex3f(-3.8f, 0.01f, z - 1.0f);
            glVertex3f(-4.0f, 0.01f, z - 1.0f);
        glEnd();

        // Center lane divider
        glBegin(GL_QUADS);
            glVertex3f(-0.2f, 0.01f, z);
            glVertex3f(0.2f, 0.01f, z);
            glVertex3f(0.2f, 0.01f, z - 1.0f);
            glVertex3f(-0.2f, 0.01f, z - 1.0f);
        glEnd();

        // Right lane divider
        glBegin(GL_QUADS);
            glVertex3f(3.8f, 0.01f, z);
            glVertex3f(4.0f, 0.01f, z);
            glVertex3f(4.0f, 0.01f, z - 1.0f);
            glVertex3f(3.8f, 0.01f, z - 1.0f);
        glEnd();
    }

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