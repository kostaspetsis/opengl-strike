#ifndef __VERTEX_H__
#define __VERTEX_H__
class Vertex{
public:
	Vertex():x(0),y(0),z(0),tx(0),ty(0){}
	Vertex(float _x, float _y, float _z):x(_x), y(_y), z(_z){
		tx=ty=0.f;
	}

	void serialize(){
		std::cout << "Vertex(" << x <<","<<y<<","<<z<<")";
		std::cout << "\t(" << tx <<","<<ty<<")"<<std::endl;
	}

	float x,y,z;
	float tx,ty;
};

#endif