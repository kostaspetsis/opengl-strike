#ifndef __XMLITEM_H__
#define __XMLITEM_H__

#include <iostream>
#include <string>
#include <map>
#include <vector>

class XMLItem{
public:
	XMLItem(std::string label){value = label;}
	std::vector<std::map<std::string, std::string>> attributes;
	std::string value;//name of xmlitem
	std::vector<XMLItem*> childs;
	std::vector<XMLItem*> siblings;
	XMLItem* Child(XMLItem *item){
		childs.push_back(item);
		return this;
	}
	XMLItem* Attr(std::string a,std::string v){
		std::map<std::string,std::string> mapper;
		mapper[a] = v;
		attributes.push_back(mapper);
		return this;
	}
	void Print(){
		std::cout << value;
	}
	void PrintChilds(){
		// std::cout << "{";
		// for(auto ch : childs){
		// 	ch->Print();
		// 	std::cout << ", ";
		// }
		// std::cout << "}" << std::endl;
		static int i = 0;
		i++;
		std::cout << "<" << value;
		
		for(auto m : attributes){
			for( auto const& [key, val] : m )
			{
				std::cout << " " << key         // string (key)
						<< "=\""  
						<< val << "\"";        // string's value
			}
		}
		std::cout << ">\n";
		// std::cout << "\n";
		for(int y = 0; y < i; y++){
			std::cout << "\t";
		}
		for(auto ch : childs){
			// std::cout << "\n\t<"<<ch->value<<">";
			
			ch->PrintChilds();
			// i=0;
			// ch->Print();
			// std::cout << ", ";
		}
		std::cout << "\n";
		// std::cout<<i;
		for(int y = 0; y < i-1; y++){
			std::cout << "\t";
		}
		std::cout << "</" <<value<<">";
		std::cout << "\n";
		for(int y = 0; y < i-1; y++){
			std::cout << "\t";
		}
		i--;
	}
	void parseTree(XMLItem* root){
			root->PrintChilds();
	}
};


// XMLItem *Model=new XMLItem("Model");
// XMLItem *Transform=new XMLItem("Transform");
// 	XMLItem *Position=new XMLItem("Position");
// 		XMLItem *Vec3=new XMLItem("Vec3");
// 	XMLItem *Rotation=new XMLItem("Rotation");
// 		XMLItem *Vec31=new XMLItem("Vec31");		
// 	XMLItem *Scale=new XMLItem("Scale");
// 		XMLItem *Vec32= new XMLItem("Vec32");
// XMLItem *Texture= new XMLItem("Texture");



// Model
// ->Child(Transform
// 		->Child(Position
// 				->Child(Vec3->Attr("x","10")->Attr("y","0")->Attr("z","0") ) )
// 		->Child(Rotation->Attr("angle","0")
// 				->Child(Vec31->Attr("x","1")->Attr("y","0")->Attr("z","0")) )
// 		->Child(Scale
// 				->Child(Vec32->Attr("x","1")->Attr("y","1")->Attr("z","1")) )) 
// ->Child(Texture->Attr("bUseTexture","true")->Attr("label","floor")->Attr("path","data/cube_checkerboard.bmp"));

// Model->parseTree(Model);

#endif