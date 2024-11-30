#ifndef TEXTURE_BUILDER_H
#define TEXTURE_BUILDER_H

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>

#ifdef __APPLE__
// macOS-specific includes
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
// Windows-specific includes
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#pragma comment(lib, "glew32.lib")
#endif

// Load a PPM file into an OpenGL texture
void loadPPM(GLuint* textureID, char* strFileName, int width, int height, int wrap) {
    unsigned char* data; // Use unsigned char instead of BYTE
    FILE* pFile;

#ifdef __APPLE__
    pFile = fopen(strFileName, "r"); // Use fopen for cross-platform compatibility
#else
    fopen_s(&pFile, strFileName, "r"); // Use fopen_s for Windows
#endif

    if (pFile) {
        data = (unsigned char*)malloc(width * height * 3); // Allocate memory for texture data
        fread(data, 1, width * height * 3, pFile);
        fclose(pFile);
    } else {
        printf("Error: Texture file not found! [%s]\n", strFileName);
        exit(EXIT_FAILURE);
    }

    glGenTextures(1, textureID);
    glBindTexture(GL_TEXTURE_2D, *textureID);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap ? GL_REPEAT : GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap ? GL_REPEAT : GL_CLAMP);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    free(data); // Free allocated memory
}

// Load a BMP file into an OpenGL texture
void loadBMP(GLuint* textureID, char* strFileName, int wrap) {
#ifdef __APPLE__
    // macOS Implementation: Load BMP directly using standard I/O
    FILE* pFile = fopen(strFileName, "rb");
    if (!pFile) {
        printf("Error: Texture file not found! [%s]\n", strFileName);
        exit(EXIT_FAILURE);
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, pFile);  // Read BMP header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int dataSize = width * height * 3;

    unsigned char* data = (unsigned char*)malloc(dataSize); // Use unsigned char for pixel data
    fread(data, sizeof(unsigned char), dataSize, pFile);
    fclose(pFile);

    // OpenGL texture setup
    glGenTextures(1, textureID);
    glBindTexture(GL_TEXTURE_2D, *textureID);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap ? GL_REPEAT : GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap ? GL_REPEAT : GL_CLAMP);

    free(data); // Free allocated memory

#else
    // Windows Implementation using glaux
    AUX_RGBImageRec* pBitmap = auxDIBImageLoadA(strFileName);
    if (!pBitmap) {
        printf("Error: Texture file not found! [%s]\n", strFileName);
        exit(EXIT_FAILURE);
    }

    glGenTextures(1, textureID);
    glBindTexture(GL_TEXTURE_2D, *textureID);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, pBitmap->sizeX, pBitmap->sizeY, GL_RGB, GL_UNSIGNED_BYTE, pBitmap->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap ? GL_REPEAT : GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap ? GL_REPEAT : GL_CLAMP);

    if (pBitmap) {
        if (pBitmap->data) {
            free(pBitmap->data);
        }
        free(pBitmap);
    }
#endif
}

#endif  // TEXTURE_BUILDER_H