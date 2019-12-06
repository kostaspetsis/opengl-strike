#include "Model.h"


Model::Model(std::vector<Vertex> _vertices, std::vector<Face> _faces){
	vertices = _vertices;
	faces = _faces;
}

void Model::render(){
	for( Face face : faces){

		glBegin(GL_TRIANGLES);	
			glTexCoord2f(vertices[face.indices[0]].tx, vertices[face.indices[0]].ty);
			glVertex3f(vertices[face.indices[0]].x,vertices[face.indices[0]].y, vertices[face.indices[0]].z);
			
			glTexCoord2f(vertices[face.indices[1]].tx, vertices[face.indices[1]].ty);
			glVertex3f(vertices[face.indices[1]].x,vertices[face.indices[1]].y, vertices[face.indices[1]].z);
			
			glTexCoord2f(vertices[face.indices[2]].tx, vertices[face.indices[2]].ty);
			glVertex3f(vertices[face.indices[2]].x,vertices[face.indices[2]].y, vertices[face.indices[2]].z);
			
		glEnd();
	}
}

void Model::serialize(){
	for (Vertex v : vertices){
		v.serialize();
	}
	for(Face f : faces){
		f.serialize();
	}

}

