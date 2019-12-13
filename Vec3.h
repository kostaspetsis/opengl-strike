#ifndef __VEC3F_H__
#define __VEC3F_H__

#include <iostream>
#include <string>

#include "Vec2f.h"
#include "common.h"
class Vec3 : public Vec2f{
public:
	Vec3():Vec2f(),z(0.0){}
	Vec3(float _x, float _y, float _z):Vec2f(_x,_y),z(_z){}
	std::string Serialize(){
		std::string serialized;
		serialized +=  "(" + std::to_string(x) + ", " + std::to_string(y) + ", "+std::to_string(z)+")"+endline;
		// std::cout << serialized;
		return serialized;
	}
	float z;
};

#endif