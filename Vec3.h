#ifndef __VEC3F_H__
#define __VEC3F_H__
#include "Vec2f.h"

class Vec3 : public Vec2f{
public:
	Vec3():Vec2f(),z(0.0){}
	Vec3(float _x, float _y, float _z):Vec2f(_x,_y),z(_z){}
	void serialize(){
		std::cout << "(" << x << ", " << y << ", "<<z<<")"<<std::endl;
	}
	float z;
};

#endif