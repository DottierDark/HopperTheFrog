#ifndef MODEL_H
#define MODEL_H

// Include platform-specific OpenGL headers
#ifdef __APPLE__
#include <GLUT/glut.h> // macOS
#elif _WIN32
#include <windows.h>   // Required for Windows
#include <GL/glut.h>
#else
#include <GL/glut.h>   // Linux/other platforms
#endif

#include <assimp/Importer.hpp>    // Assimp importer
#include <assimp/scene.h>         // Assimp scene structure
#include <assimp/postprocess.h>   // Assimp post-processing flags


#include <string>
#include <vector>

class Model {
public:
    // Constructor and Destructor
    Model();
    ~Model();

    // Load a 3D model from file
    bool loadModel(const std::string& filePath);


    // Render the loaded model
    void render();



private:
    // Helper methods for processing Assimp data
    void processNode(aiNode* node, const aiScene* scene);
    void processMesh(aiMesh* mesh, const aiScene* scene);


    // Vertex data
    std::vector<float> vertices;      // Vertex positions
    std::vector<float> normals;       // Normals
    std::vector<float> texCoords;     // Texture coordinates
};

#endif // MODEL_H