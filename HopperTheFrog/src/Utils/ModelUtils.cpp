#include "ModelUtils.h"
#include <iostream>

static const aiScene* scene = nullptr;  // Static scene to hold model data
static Assimp::Importer importer;

bool ModelUtils::loadModel(const char* filePath) {
    scene = importer.ReadFile(filePath, aiProcess_Triangulate | aiProcess_FlipUVs);
    if (!scene) {
        std::cerr << "Error loading model: " << importer.GetErrorString() << std::endl;
        return false;
    }
    return true;
}

void renderNode(const aiNode* node, const aiScene* scene) {
    for (unsigned int i = 0; i < node->mNumMeshes; i++) {
        const aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];

        glBegin(GL_TRIANGLES);
        for (unsigned int j = 0; j < mesh->mNumVertices; j++) {
            if (mesh->mTextureCoords[0]) {
                glTexCoord2f(mesh->mTextureCoords[0][j].x, mesh->mTextureCoords[0][j].y);
            }
            glVertex3f(mesh->mVertices[j].x, mesh->mVertices[j].y, mesh->mVertices[j].z);
        }
        glEnd();
    }

    for (unsigned int i = 0; i < node->mNumChildren; i++) {
        renderNode(node->mChildren[i], scene);
    }
}

void ModelUtils::renderModel() {
    if (scene && scene->mRootNode) {
        renderNode(scene->mRootNode, scene);
    }
}