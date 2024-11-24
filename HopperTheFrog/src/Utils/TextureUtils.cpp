#include <Utils/TextureUtils.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>

GLuint loadTexture(const char* filename) {
    GLuint textureID;
    glGenTextures(1, &textureID);  // Generate texture ID
    glBindTexture(GL_TEXTURE_2D, textureID);  // Bind the texture

    int width, height, nrChannels;
    unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);
    if (data) {
        // Determine the format based on the number of channels
        int format = (nrChannels == 4) ? GL_RGBA : GL_RGB;
        
        // Upload the texture data to OpenGL
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);  // Generate mipmaps
    } else {
        std::cout << "Failed to load texture: " << filename << std::endl;
    }
    stbi_image_free(data);  // Free image memory

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return textureID;
}