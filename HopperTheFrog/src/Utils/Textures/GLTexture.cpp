#include "GLTexture.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype> // Ensure this is included at the top for tolower

#ifdef __APPLE__
// macOS includes
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
// Windows includes
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "GLAUX.H"
#pragma comment(lib, "glaux")
#endif

//////////////////////////////////////////////////////////////////////
// Constructor and Destructor
//////////////////////////////////////////////////////////////////////

GLTexture::GLTexture() : texturename(nullptr), width(0), height(0) {
    texture[0] = 0;
}

GLTexture::~GLTexture() {
    if (texturename) {
        free(texturename);
    }
}

//////////////////////////////////////////////////////////////////////
// Load Texture Based on File Type
//////////////////////////////////////////////////////////////////////

void GLTexture::Load(const char* name) {
    // Convert the texture name to lowercase
    texturename = strdup(name);
    for (char* p = texturename; *p; ++p) {
        *p = std::tolower(static_cast<unsigned char>(*p)); // Use std::tolower safely
    }

    // Check the file extension and load accordingly
    if (strstr(texturename, ".bmp")) {
        LoadBMP(texturename);
    } else if (strstr(texturename, ".tga")) {
        LoadTGA(texturename);
    } else {
        printf("Unsupported file format: %s\n", texturename);
    }
}

//////////////////////////////////////////////////////////////////////
// Bind the Texture for OpenGL Use
//////////////////////////////////////////////////////////////////////

void GLTexture::Use() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
}

//////////////////////////////////////////////////////////////////////
// Load BMP File
//////////////////////////////////////////////////////////////////////

void GLTexture::LoadBMP(const char* name) {
#ifdef __APPLE__
    // macOS implementation
    FILE* file = fopen(name, "rb");
    if (!file) {
        printf("Failed to open BMP file: %s\n", name);
        return;
    }

    unsigned char header[54];
    fread(header, 1, 54, file);
    if (header[0] != 'B' || header[1] != 'M') {
        fclose(file);
        printf("Invalid BMP file: %s\n", name);
        return;
    }

    width = *(int*)&header[18];
    height = *(int*)&header[22];
    int dataSize = width * height * 3;

    unsigned char* data = (unsigned char*)malloc(dataSize);
    fread(data, 1, dataSize, file);
    fclose(file);

    // OpenGL texture setup
    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_BGR, GL_UNSIGNED_BYTE, data);

    free(data);
#else
    // Windows implementation using GLAUX
    AUX_RGBImageRec* image = auxDIBImageLoad(name);
    if (!image) {
        printf("Failed to load BMP file: %s\n", name);
        return;
    }

    width = image->sizeX;
    height = image->sizeY;

    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, image->data);

    if (image->data) {
        free(image->data);
    }
    free(image);
#endif
}

//////////////////////////////////////////////////////////////////////
// Load TGA File
//////////////////////////////////////////////////////////////////////

void GLTexture::LoadTGA(const char* name) {
    GLubyte TGAheader[12] = {0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Uncompressed TGA header
    GLubyte TGAcompare[12];
    GLubyte header[6];
    GLuint bytesPerPixel, imageSize, type = GL_RGBA;
    GLubyte* imageData;

    FILE* file = fopen(name, "rb");
    if (!file) {
        printf("Failed to open TGA file: %s\n", name);
        return;
    }

    if (fread(TGAcompare, 1, sizeof(TGAcompare), file) != sizeof(TGAcompare) ||
        memcmp(TGAheader, TGAcompare, sizeof(TGAheader)) != 0 ||
        fread(header, 1, sizeof(header), file) != sizeof(header)) {
        fclose(file);
        printf("Invalid TGA file: %s\n", name);
        return;
    }

    width = header[1] * 256 + header[0];
    height = header[3] * 256 + header[2];
    bytesPerPixel = header[4] / 8;
    imageSize = width * height * bytesPerPixel;

    if (width <= 0 || height <= 0 || (header[4] != 24 && header[4] != 32)) {
        fclose(file);
        printf("Invalid TGA file: %s\n", name);
        return;
    }

    imageData = (GLubyte*)malloc(imageSize);
    if (!imageData || fread(imageData, 1, imageSize, file) != imageSize) {
        if (imageData) free(imageData);
        fclose(file);
        printf("Failed to load TGA file: %s\n", name);
        return;
    }

    fclose(file);

    // Swap R and B values for OpenGL
    for (GLuint i = 0; i < imageSize; i += bytesPerPixel) {
        GLubyte temp = imageData[i];
        imageData[i] = imageData[i + 2];
        imageData[i + 2] = temp;
    }

    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    gluBuild2DMipmaps(GL_TEXTURE_2D, (bytesPerPixel == 4 ? GL_RGBA : GL_RGB), width, height,
                      (bytesPerPixel == 4 ? GL_RGBA : GL_RGB), GL_UNSIGNED_BYTE, imageData);

    free(imageData);
}

//////////////////////////////////////////////////////////////////////
// Build a Solid Color Texture
//////////////////////////////////////////////////////////////////////

void GLTexture::BuildColorTexture(unsigned char r, unsigned char g, unsigned char b) {
    unsigned char data[12];
    for (int i = 0; i < 12; i += 3) {
        data[i] = r;
        data[i + 1] = g;
        data[i + 2] = b;
    }

    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, 2, 2, GL_RGB, GL_UNSIGNED_BYTE, data);
}

//////////////////////////////////////////////////////////////////////