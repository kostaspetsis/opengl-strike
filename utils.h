#ifndef __UTILS_H__
#define __UTILS_H__
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdio.h>

#include "Model.h"
#include "Vertex.h"
#include "Face.h"
#include "Logging.h"
#include "GraphicsEngine.h"

class Model;
namespace utils{
		
	/* Image type - contains height, width, and data */
	struct Image 
	{
		unsigned long sizeX;
		unsigned long sizeY;
		GLubyte *data;
	};
	// std::vector<Vertex> LoadModel(std::string name);
	Model loadObj(const char* fname);
	int ImageLoad(char *filename, Image *image);
	unsigned int getint(FILE *fp);
	unsigned short getshort(FILE* fp);
	// Load Bitmaps And Convert To Textures
	GLuint LoadGLTexture(char *fileName);
}

#endif