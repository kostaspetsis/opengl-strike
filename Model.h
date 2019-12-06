#ifndef __MODEL_H__
#define __MODEL_H__
#include <iostream>
#include <vector>
#include <string>

#include "utils.h"
#include "Vertex.h"
#include "Face.h"
#include "GraphicsEngine.h"
#include "Vec2f.h"



class Model{
public:
	Model(){}
	Model(std::vector<Vertex> _vertices, std::vector<Face> _faces);
	// Model& operator=(Model m){
	// 	this->vertices = m.vertices;
	// 	this->faces = m.faces;
	// 	return this;
	// }
	std::vector<Vertex> vertices;
	std::vector<Face> faces;
	std::vector<Vec2f> texCoords;
	// std::vector<GLuint> textureIds;
	GLuint *textureId;
	std::string textureLabel;
	bool bUseTexture;
	void useTexture(GLuint *id, bool use=true);
	void useTexture(std::string textureName);
	void render();
	void serialize();
};	

#endif