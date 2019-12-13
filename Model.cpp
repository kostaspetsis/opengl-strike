#include "Model.h"
#include <chrono>
#include <thread>

extern std::map<std::string, GLuint*> textures;
extern float varx,vary,varz;
extern float timeline[5];
static int i;
Model::Model(std::vector<Vertex> _vertices, std::vector<Face> _faces){
	vertices = _vertices;
	faces = _faces;
	i=0;
}

void Model::render(){
	if(bUseTexture){
		glEnable(GL_TEXTURE_2D);
		int pos = utils::getTexturePos(textureLabel);
		// std::cout << "pos = " << pos << std::endl;
		pos=0;
		// glActiveTexture(GL_TEXTURE0 +pos);
		glBindTexture(GL_TEXTURE_2D, *textureId);
	}
	else{
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	glTranslatef(pos.x,pos.y,pos.z);
	//glColor3f(1.0,0.23,0.27);
	glScalef(scale.x,scale.y,scale.z);
	glRotatef(angle, rot.x,rot.y,rot.z);
	glBegin(GL_TRIANGLES);	
		for( Face face : faces){
			// glTexCoord2f(vertices[face.indices[0]].tx, vertices[face.indices[0]].ty);
			glTexCoord2f(texCoords[face.texIndices[0]].x, texCoords[face.texIndices[0]].y);
			glVertex3f(vertices[face.vertIndices[0]].x,vertices[face.vertIndices[0]].y, vertices[face.vertIndices[0]].z);
			
			// glTexCoord2f(vertices[face.vertIndices[1]].tx, vertices[face.vertIndices[1]].ty);
			glTexCoord2f(texCoords[face.texIndices[1]].x, texCoords[face.texIndices[1]].y);
			glVertex3f(vertices[face.vertIndices[1]].x,vertices[face.vertIndices[1]].y, vertices[face.vertIndices[1]].z);
			
			// glTexCoord2f(vertices[face.vertIndices[2]].tx, vertices[face.vertIndices[2]].ty);
			glTexCoord2f(texCoords[face.texIndices[2]].x, texCoords[face.texIndices[2]].y);
			glVertex3f(vertices[face.vertIndices[2]].x,vertices[face.vertIndices[2]].y, vertices[face.vertIndices[2]].z);
		}
	glEnd();
	/*vertices[1].x = varx;
	vertices[1].y = vary;
	vertices[1].z = varz;
	vertices[0].x=timeline[(i++)%5];
	std::this_thread::sleep_for(std::chrono::milliseconds(500));*/
}

void Model::serialize(){
	for (Vertex v : vertices){
		v.serialize();
	}
	for(Face f : faces){
		f.serialize();
	}
	std::cout << texCoords.size()<<std::endl;
	std::cout << "Pos-> ";pos.serialize();
	std::cout << "Rot-> ";rot.serialize();
	std::cout << "Scale-> ";scale.serialize();
	std::cout <<"rotation angle="<<angle<<std::endl;
}


void Model::useTexture(GLuint *id, bool use){
	textureId = id;
	bUseTexture = (use)?true:false;
}
void Model::useTexture(std::string textureName){
	textureId = textures[textureName];
	std::cout << "textureId = " << *textureId<<std::endl;
	textureLabel = textureName;
	bUseTexture=true;
}
