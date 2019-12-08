#include "Scene.h"


extern std::vector<GLuint*> textureIds;

void Scene::LoadScene(std::string fileName){

	TiXmlDocument doc;
	if(!doc.LoadFile(fileName.c_str())){
		std::cerr << doc.ErrorDesc() << std::endl;
		return;
	}


	//Get data
	TiXmlElement* root = doc.FirstChildElement();
	if(root == NULL)
	{
		std::cerr << "Failed to load file: No root element."
			<< std::endl;
		doc.Clear();
		return;
	}

	//Loop through all elements-childrens of root element
	for(TiXmlElement* elemModel = root->FirstChildElement(); elemModel != NULL; elemModel = elemModel->NextSiblingElement()){
		std::string elemName = elemModel->Value();
		std::cout << elemName << std::endl;
		const char* attr;
		if(elemName == "Model"){
			Model *model = new Model();
			Model model1;
			model1 = utils::loadObj(elemModel->Attribute("path"));

			model->vertices = model1.vertices;
			model->faces = model1.faces;
			model->texCoords = model1.texCoords;
			
			TiXmlElement *elemTransform,*elemPos,*elemRot,*elemScale,*elemTexture;
			elemTransform = elemModel;
			elemTransform = elemTransform->FirstChildElement("Transform");
			
			if (!elemTransform){
				std::cout << "No transform";
			}
			elemPos = elemTransform->FirstChildElement("Position");
			elemPos = elemPos->FirstChildElement("Vec3");
			if(!elemPos){
				std::cout <<"No vec3 in Position" << std::endl;
			}
			std::cout << elemPos->Value() << std::endl;
			std::cout << "\t";
			std::cout << elemPos->Attribute("x")<<std::endl;
			std::cout << "\t";
			std::cout << elemPos->Attribute("y")<<std::endl;
			std::cout << "\t";
			std::cout << elemPos->Attribute("z")<<std::endl;
			model->pos.x=std::stof(elemPos->Attribute("x"));
			model->pos.y=std::stof(elemPos->Attribute("y"));
			model->pos.z=std::stof(elemPos->Attribute("z"));
			elemRot = elemTransform->FirstChildElement("Rotation")->FirstChildElement("Vec3");
			if(!elemRot){
				std::cout <<"No vec3 in Rotation" << std::endl;
			}
			std::cout << elemRot->Value() << std::endl;
			std::cout << "\t";
			std::cout << elemTransform->FirstChildElement("Rotation")->Attribute("angle")<<std::endl;
			std::cout << "\t";
			std::cout << elemRot->Attribute("x")<<std::endl;
			std::cout << "\t";
			std::cout << elemRot->Attribute("y")<<std::endl;
			std::cout << "\t";
			std::cout << elemRot->Attribute("z")<<std::endl;
			model->rot.x=std::stof(elemRot->Attribute("x"));
			model->rot.y=std::stof(elemRot->Attribute("y"));
			model->rot.z=std::stof(elemRot->Attribute("z"));
			model->angle=std::stof(elemTransform->FirstChildElement("Rotation")->Attribute("angle"));
			
			elemScale = elemTransform->FirstChildElement("Scale")->FirstChildElement("Vec3");
			if(!elemScale){
				std::cout <<"No vec3 in Scale" << std::endl;
			}
			// std::cout << elemScale->Value() << std::endl;
			// std::cout << "\t";
			// std::cout << elemScale->Attribute("x")<<std::endl;
			// std::cout << "\t";
			// std::cout << elemScale->Attribute("y")<<std::endl;
			// std::cout << "\t";
			// std::cout << elemScale->Attribute("z")<<std::endl;
			model->scale.x=std::stof(elemScale->Attribute("x"));
			model->scale.y=std::stof(elemScale->Attribute("y"));
			model->scale.z=std::stof(elemScale->Attribute("z"));
			std::cout << model->scale.x;
			elemTexture = elemModel->FirstChildElement("Texture");
			std::string path(elemTexture->Attribute("path"));
			std::string label(elemTexture->Attribute("label"));
			if(path != ""){
				textureIds.push_back(utils::LoadGLTexture(const_cast<char*>(elemTexture->Attribute("path")), const_cast<char*>(elemTexture->Attribute("label"))));
			}
			if (std::string(elemTexture->Attribute("bUseTexture")) == "true"){
				model->useTexture(label);
				std::cout << "Using texture " << label << std::endl;
			}else{
				std::cout << "Not using texture" << std::endl;
				model->useTexture(0,false);
			}
			Add(model);
			model->serialize();
		}
		
	}
}