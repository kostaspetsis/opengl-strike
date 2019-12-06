#ifndef __VEC2F_H__
#define __VEC2F_H__

class Vec2f{
public:
	Vec2f():x(0.f),y(0.f){}
	Vec2f(float _x, float _y):x(_x),y(_y){}
	float x,y;
};

#endif