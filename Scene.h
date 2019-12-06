#ifndef __SCENE_H__
#define __SCENE_H__

#include <vector>
#include <iostream>
#include "Model.h"
#include "utils.h"

class Scene{
public:
	Scene(){}
	void Add(Model *model){
		models.push_back(model);
	}
	
	void render(){
		for(Model *model: models){
			model->render();
		}
	}
	std::vector<Model*> models;
};

#endif