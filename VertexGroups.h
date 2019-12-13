#ifndef __VERTEX_GROUPS_H__
#define __VERTEX_GROUPS_H__
#include <vector>
#include <map>
#include <string>

#include "Vertex.h"

class VertexGroups{
public:
	VertexGroups(){}
	VertexGroups(){}
	void Add(std::string name, int index, float weight){
		std::map<int,float> indexWeight;
		indexWeight[index] = weight;
		weights.push_back(std::make_pair(name,indexWeight));
	}
	// std::string name;
	std::vector<std::pair<std::string,std::map<int,float>>> weights;
};

#endif