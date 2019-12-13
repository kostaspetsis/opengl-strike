#ifndef __HIERARCHY_H__
#define __HIERARCHY_H__

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "common.h"

// template <class T>
// class HierarchyItem{
// public:
// 	HierarchyItem(){}
// 	HierarchyItem(T _data){data=_data;}
// 	T data;
// 	// std::vector<std::map<std::string, std::string>> attributes;
// 	std::vector<HierarchyItem*> childs;
// 	std::vector<HierarchyItem*> siblings;
// 	HierarchyItem* Child(HierarchyItem *item){
// 		childs.push_back(item);
// 		return this;
// 	}
// 	// Hierarchy* Attr(std::string a,std::string v){
// 	// 	std::map<std::string,std::string> mapper;
// 	// 	mapper[a] = v;
// 	// 	attributes.push_back(mapper);
// 	// 	return this;
// 	// }
// 	void PrintChilds(){
// 		this->Serialize();
// 		for (auto ch : childs){
// 			ch->PrintChilds();
// 		}
// 	}
// 	void Serialize(){
// 		// data
// 		data->Serialize();
// 	}
// };

template <class T>
class HierarchyItem{
public:
	HierarchyItem(){}
	HierarchyItem(T _data){data=_data;}
	T data;
	// std::vector<std::map<std::string, std::string>> attributes;
	std::vector<HierarchyItem*> childs;
	std::vector<HierarchyItem*> siblings;
	HierarchyItem* Child(T item){
		HierarchyItem<T> *item1 = new HierarchyItem<T>(item);
		childs.push_back(item1);
		return this;
	}
	// Hierarchy* Attr(std::string a,std::string v){
	// 	std::map<std::string,std::string> mapper;
	// 	mapper[a] = v;
	// 	attributes.push_back(mapper);
	// 	return this;
	// }
	// 
	

	std::string PrintChilds(std::string indent, bool last){
// https://stackoverflow.com/questions/1649027/how-do-i-print-out-a-tree-structure
		std::cout << indent;
       if (last)
       {
        //   std::cout <<END_BRA;
           indent += HIERARCHY_ARROW;
       }
       else
       {
        //   std::cout << BEGIN_BRA;
           indent += HIERARCHY_ARROW;
       }
       std::cout << Serialize(indent);

       for (int i = 0; i < childs.size(); i++){
           childs[i]->PrintChilds(indent, i == childs.size() - 1);
  	 	}
	   return "";
	}
	std::string Serialize(std::string prefix=""){
		// data
		return data->SerializePrefixed(prefix);
	}
};
template <class T>
class Hierarchy{
public:
	Hierarchy(){
		head=nullptr;
	}
	Hierarchy(T _head){head=new HierarchyItem<T>(_head);}
	HierarchyItem<T>* head;
	
	void AddChild(T bone1, T boneToAdd){
		int i = 0;
		for(HierarchyItem<T> *item1=head; item1 != NULL;){
			if(item1->data == bone1){
				// std::cout << "name:" << item1->data->name<<endline;
				item1->Child(boneToAdd);
				// std::cout << "Mpike";
				break;
			}
			else{
				// std::cout << "name:" << item1->data->name<<endline;
			}
			item1 = head->childs[i];
			i++;
		}
	}

	void parseTree(){
		head->PrintChilds("",false);
	}
};

// template <class T>
// class Hierarchy{
// public:
// 	Hierarchy(){
// 		head=nullptr;
// 	}
// 	Hierarchy(T *_head){head=_head;}
// 	T *head;
	
// 	void PrintChilds(){
// 		// std::cout << "{";
// 		// for(auto ch : childs){
// 		// 	ch->Print();
// 		// 	std::cout << ", ";
// 		// }
// 		// std::cout << "}" << std::endl;
// 		static int i = 0;
// 		i++;
// 		std::cout << "<" << head->Serialize();
		
// 		// for(auto item : attributes){
// 			// for( auto const& [key, val] : m )
// 		// for (auto item : head->childs){
			
// 		// }
// 		head->Serialize();
		
// 		std::cout << ">\n";
// 		// std::cout << "\n";
// 		for(int y = 0; y < i; y++){
// 			std::cout << "\t";
// 		}
// 		for(auto ch : head->childs){
// 			// std::cout << "\n\t<"<<ch->value<<">";
			
// 			ch->PrintChilds();
// 			// i=0;
// 			// ch->Print();
// 			// std::cout << ", ";
// 		}
// 		std::cout << "\n";
// 		// std::cout<<i;
// 		for(int y = 0; y < i-1; y++){
// 			std::cout << "\t";
// 		}
// 		std::cout << "</" <<head->Serialize()<<">";
// 		std::cout << "\n";
// 		for(int y = 0; y < i-1; y++){
// 			std::cout << "\t";
// 		}
// 		i--;
// 	}
// 	void parseTree(T *root){
// 		root->PrintChilds();
// 	}
// };

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


#endif // !__HIERARCHY_H__