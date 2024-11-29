#ifndef MODEL_3DS_H
#define MODEL_3DS_H

#include <vector>
#include <glew.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "GLTexture.h"

class Model_3DS {
public:
	struct Mesh {
		GLuint VAO, VBO, EBO;
		unsigned int numIndices;
		GLTexture texture;
	};

	std::vector<Mesh> meshes;
	Model_3DS();
	~Model_3DS();

	bool Load(const std::string& filepath); // Load model using Assimp
	void Draw();                            // Render the model
};

#endif // MODEL_3DS_H
