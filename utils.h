#ifndef __UTILS_H__
#define __UTILS_H__
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <random>
#include <functional> //for std::function
#include <algorithm>  //for std::generate_n
#include <stdlib.h>

#include "Model.h"
#include "Vertex.h"
#include "Face.h"
#include "Logging.h"
#include "GraphicsEngine.h"
#include "Types.h"
#include "Vec2f.h"

//forward declarations
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
	GLuint* LoadGLTexture(char *fileName, char* name=NULL);
	// GLuint* LoadGLTexture(std::string fileName, std::string name=NULL){
	// 	return LoadGLTexture(fileName.c_str(), name.c_str());
	// }

	// given a function that generates a random character,
	// return a string of the requested length
	std::string random_string( size_t length );
	
	char_array charset();
	GLuint* getTextureId(std::string str);
	int getTexturePos(std::string str);
	
}

#endif