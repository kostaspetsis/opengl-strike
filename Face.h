#ifndef __FACE_H__
#define __FACE_H__
#include <iostream>
class Face{
public:
	Face(){}
	Face(int id1, int id2, int id3){
		indices[0]=id1;indices[1]=id2;indices[2]=id3;
	}
	void serialize(){
		std::cout << indices[0] << ", " << indices[1] << ", " << indices[2]<<std::endl;
	}
	int indices[3];
};
#endif