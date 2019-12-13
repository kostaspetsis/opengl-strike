#ifndef __BONE_H__
#define __BONE_H__

#include <iostream>
#include <string>
#include "common.h"
#include "Vec3.h"

class Bone{
public:
	Bone(){}
	Bone(std::string _name, bool _SerializeVerbose=true){
		name = _name;
		SerializeVerbose=_SerializeVerbose;
	}
	std::string Serialize(){
		std::string serialized;
		serialized += BEGIN_BRA + "Bone name: " + name + "\n" ;
		if ( SerializeVerbose ){
			serialized += MIDDLE_BRA + "Position: ";
			serialized += pos.Serialize();
			serialized += MIDDLE_BRA + "Angle rot: " + std::to_string(angle) + endline;
			serialized += MIDDLE_BRA + "Rotation: ";
			serialized += rot.Serialize();
			serialized += END_BRA + "Scale: ";
			serialized += scale.Serialize();
		}
		return serialized;
	}
	std::vector<std::string> SerializeWList(std::string prefix){
		std::vector<std::string> v;
		v.push_back(prefix + BEGIN_BRA+ "Bone name: " + name +endline);
		if(SerializeVerbose){
			v.push_back(prefix + MIDDLE_BRA+  "Position: ");
			v.push_back(pos.Serialize());
			v.push_back(prefix + MIDDLE_BRA+"Angle rot: " + std::to_string(angle) + endline);
			v.push_back(prefix + MIDDLE_BRA+  "Rotation: ");
			v.push_back(pos.Serialize());
			v.push_back(prefix + END_BRA +  "Scale: ");
			v.push_back( pos.Serialize()+endline);
		}

		return v;
	}

	std::string SerializePrefixed(std::string prefix){
		std::vector<std::string> v = SerializeWList(prefix);
		std::string joined= Join(v);
		return joined;
	}

	Vec3 pos,rot,scale;
	float angle;
	std::string name;

	bool SerializeVerbose=false;
};

#endif // !__BONE_H__