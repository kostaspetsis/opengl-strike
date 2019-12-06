#ifndef __FACE_H__
#define __FACE_H__
#include <iostream>
class Face{
public:
	Face(){}
	Face(int id1, int id2, int id3){
		vertIndices[0]=id1;vertIndices[1]=id2;vertIndices[2]=id3;
	}
	void serialize(){
		std::cout << vertIndices[0] << ", " << vertIndices[1] << ", " << vertIndices[2]<<std::endl;
	}
	int vertIndices[3];
	int texIndices[3];
};
#endif