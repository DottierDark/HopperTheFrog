#include "Model_3DS.h"
#include <iostream>

Model_3DS::Model_3DS() {}

Model_3DS::~Model_3DS() {
	for (auto& mesh : meshes) {
		glDeleteVertexArrays(1, &mesh.VAO);
		glDeleteBuffers(1, &mesh.VBO);
		glDeleteBuffers(1, &mesh.EBO);
	}
}

bool Model_3DS::Load(const std::string& filepath) {
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(filepath, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
		std::cerr << "Assimp error: " << importer.GetErrorString() << std::endl;
		return false;
	}

	for (unsigned int i = 0; i < scene->mNumMeshes; ++i) {
		aiMesh* mesh = scene->mMeshes[i];
		if (!mesh) {
			std::cerr << "Null mesh at index " << i << std::endl;
			continue;
		}

		Mesh newMesh;
		std::vector<float> vertices;
		std::vector<unsigned int> indices;

		// Process vertices
		for (unsigned int j = 0; j < mesh->mNumVertices; ++j) {
			vertices.push_back(mesh->mVertices[j].x);
			vertices.push_back(mesh->mVertices[j].y);
			vertices.push_back(mesh->mVertices[j].z);

			if (mesh->HasNormals()) {
				vertices.push_back(mesh->mNormals[j].x);
				vertices.push_back(mesh->mNormals[j].y);
				vertices.push_back(mesh->mNormals[j].z);
			}

			if (mesh->mTextureCoords[0]) {
				vertices.push_back(mesh->mTextureCoords[0][j].x);
				vertices.push_back(mesh->mTextureCoords[0][j].y);
			}
			else {
				vertices.push_back(0.0f);
				vertices.push_back(0.0f);
			}
		}

		// Process indices
		for (unsigned int j = 0; j < mesh->mNumFaces; ++j) {
			aiFace face = mesh->mFaces[j];
			for (unsigned int k = 0; k < face.mNumIndices; ++k) {
				indices.push_back(face.mIndices[k]);
			}
		}

		// Generate and validate buffers
		glGenVertexArrays(1, &newMesh.VAO);
		glGenBuffers(1, &newMesh.VBO);
		glGenBuffers(1, &newMesh.EBO);

		glBindVertexArray(newMesh.VAO);

		glBindBuffer(GL_ARRAY_BUFFER, newMesh.VBO);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, newMesh.EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

		glBindVertexArray(0);

		newMesh.numIndices = indices.size();
		meshes.push_back(newMesh);
	}

	return true;
}



void Model_3DS::Draw() {
	for (const auto& mesh : meshes) {
		mesh.texture.Use();
		glBindVertexArray(mesh.VAO);
		glDrawElements(GL_TRIANGLES, mesh.numIndices, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
}
