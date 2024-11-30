#include "Model.h"
#include <iostream>

// Constructor
Model::Model() {}

// Destructor
Model::~Model() {}

// Load a 3D model using Assimp
bool Model::loadModel(const std::string& filePath) {
    Assimp::Importer importer;

    // Load the model file using Assimp
    const aiScene* scene = importer.ReadFile(filePath,
        aiProcess_Triangulate |      // Convert polygons to triangles
        aiProcess_FlipUVs |          // Flip UV mapping coordinates
        aiProcess_GenNormals |       // Generate normals if missing
        aiProcess_OptimizeMeshes);   // Optimize mesh data

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cerr << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
        return false;
    }

    // Process the root node
    processNode(scene->mRootNode, scene);
    return true;
}

// Recursively process nodes in the scene
void Model::processNode(aiNode* node, const aiScene* scene) {
    for (unsigned int i = 0; i < node->mNumMeshes; i++) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        processMesh(mesh, scene);
    }

    // Recursively process child nodes
    for (unsigned int i = 0; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene);
    }
}

// Process individual meshes in the scene
void Model::processMesh(aiMesh* mesh, const aiScene* scene) {
    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        // Add vertex positions
        vertices.push_back(mesh->mVertices[i].x);
        vertices.push_back(mesh->mVertices[i].y);
        vertices.push_back(mesh->mVertices[i].z);

        // Add normals if available
        if (mesh->HasNormals()) {
            normals.push_back(mesh->mNormals[i].x);
            normals.push_back(mesh->mNormals[i].y);
            normals.push_back(mesh->mNormals[i].z);
        }

        // Add texture coordinates if available
        if (mesh->mTextureCoords[0]) {
            texCoords.push_back(mesh->mTextureCoords[0][i].x);
            texCoords.push_back(mesh->mTextureCoords[0][i].y);
        }
    }

    // Note: Index data (for drawing elements) can be added here if needed.
}

// Render the loaded model using OpenGL
void Model::render() {
    glBegin(GL_TRIANGLES); // Render as triangles
    for (size_t i = 0; i < vertices.size(); i += 3) {
        // Set normals if available
        if (i < normals.size()) {
            glNormal3f(normals[i], normals[i + 1], normals[i + 2]);
        }

        // Set texture coordinates if available
        if (i / 3 < texCoords.size() / 2) {
            glTexCoord2f(texCoords[(i / 3) * 2], texCoords[(i / 3) * 2 + 1]);
        }

        // Set vertex positions
        glVertex3f(vertices[i], vertices[i + 1], vertices[i + 2]);
    }
    glEnd();
}
