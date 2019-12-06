#ifndef __MODEL_H__
#define __MODEL_H__
#include <iostream>
#include <vector>
#include <string>

#include "utils.h"
#include "Vertex.h"
#include "Face.h"
#include "GraphicsEngine.h"

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
	void render();
	void serialize();
};	

#endif