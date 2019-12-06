#include "Model.h"
extern std::map<std::string, GLuint*> textures;

Model::Model(std::vector<Vertex> _vertices, std::vector<Face> _faces){
	vertices = _vertices;
	faces = _faces;
}

void Model::render(){
	if(bUseTexture){
		glEnable(GL_TEXTURE_2D);
		int pos = utils::getTexturePos(textureLabel);
		std::cout << "pos = " << pos << std::endl;
		pos=0;
		// glActiveTexture(GL_TEXTURE0 +pos);
		glBindTexture(GL_TEXTURE_2D, *textureId);
	}
	else{
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	for( Face face : faces){

		glBegin(GL_TRIANGLES);	
			// glTexCoord2f(vertices[face.indices[0]].tx, vertices[face.indices[0]].ty);
			glTexCoord2f(texCoords[face.texIndices[0]].x, texCoords[face.texIndices[0]].y);
			glVertex3f(vertices[face.vertIndices[0]].x,vertices[face.vertIndices[0]].y, vertices[face.vertIndices[0]].z);
			
			// glTexCoord2f(vertices[face.vertIndices[1]].tx, vertices[face.vertIndices[1]].ty);
			glTexCoord2f(texCoords[face.texIndices[1]].x, texCoords[face.texIndices[1]].y);
			glVertex3f(vertices[face.vertIndices[1]].x,vertices[face.vertIndices[1]].y, vertices[face.vertIndices[1]].z);
			
			// glTexCoord2f(vertices[face.vertIndices[2]].tx, vertices[face.vertIndices[2]].ty);
			glTexCoord2f(texCoords[face.texIndices[2]].x, texCoords[face.texIndices[2]].y);
			glVertex3f(vertices[face.vertIndices[2]].x,vertices[face.vertIndices[2]].y, vertices[face.vertIndices[2]].z);
			
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
	std::cout << texCoords.size()<<std::endl;

}


void Model::useTexture(GLuint *id, bool use){
	textureId = id;
	bUseTexture = (use)?true:false;
}
void Model::useTexture(std::string textureName){
	textureId = textures[textureName];
	std::cout << "textureId = " << *textureId<<std::endl;
	textureLabel = textureName;
}
