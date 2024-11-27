#include <Environment/Levels/Level1/Level1.h>
#include <Utils/ModelUtils.h>

#ifdef __APPLE__
#include <GLUT/glut.h> // Include GLUT for macOS
#else
#include <GL/glut.h>   // Include GLUT for other platforms
#endif

void Level1::drawStreet() {
    std::cout << "Drawing a realistic street from 3D model..." << std::endl;

    // Load the model once at the beginning
    if (ModelUtils::loadModel("HopperTheFrog/models/street.3ds")) {
        ModelUtils::renderModel();
    } else {
        std::cerr << "Failed to load 3D street model!" << std::endl;
    }
}