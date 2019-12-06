#include "utils.h"
using namespace std;
using namespace utils;
Model utils::loadObj(const char *fname){
    std::vector<Vertex>  vertices;
    std::vector<Face> faces;
    int texCoordsRead=0;
	FILE *fp;
	int read;
	float x, y, z;
	char ch[512];
	memset(ch,'\0', 512*sizeof(char));

	fp=fopen(fname,"r");
	if (!fp) {
		printf("can't open file %s\n", fname);
		exit(1);
	}
	while(!(feof(fp))){
		read=fscanf(fp,"%s",ch);
		if (read == EOF)
			break; // EOF
		if(strcmp(ch,"v")==0){
			read=fscanf(fp,"%f %f %f",&x,&y,&z);
			if(read==3){
				// glVertex3f(x,y,z);
				vertices.push_back(Vertex(x,y,z));
				printf("v coord %f, %f, %f",x,y,z);
			}
		}else if (read==1 && strcmp(ch,"vt")==0){
			read=fscanf(fp,"%f %f",&x,&y);
			if(read==2){
				// glTexCoord2f(x,y);
				printf("tex coord %f, %f",x,y);
				vertices[texCoordsRead].tx=x;
				vertices[texCoordsRead].ty=y;
				texCoordsRead++;
			}
		}else if (read== 1 && strcmp(ch,"f")==0){
			Log("face");
			// Log(ch);
			int i[3],t[3],n[3];
			fpos_t undo_pos;
			fgetpos(fp, &undo_pos);
			read = fscanf(fp, "%d/ %d/ %d/", &i[0],&i[1],&i[2]);
			// read = fscanf(fp, "%d/ %d/ %d/", &i[0],&i[1],&i[2]);
			//index
			if (read ==3){
				Log(read);
				Log(i[0]);
				Log(i[1]);
				Log(i[2]);
				Log("face coordinates\n");
				// exit(0);
			}
			else{
				Log(read);
				Log("face2");
				//undo
				fsetpos(fp, &undo_pos);
				fgetpos(fp, &undo_pos);
				read = fscanf(fp, "%d/%d %d/%d %d/%d", &i[0],&t[0],  &i[1],&t[1],  &i[2],&t[2]);
				
				//index,texture
				if( read == 6){
					Log("read=6");
					Log( i[0]);
					Log( i[1]);
					Log( i[2]);
					Log( t[0]);
					Log( t[1]);
					Log( t[2]);
					faces.push_back(Face(i[0]-1,i[1]-1,i[2]-1));
				}
				else{
					Log(read);
				}
				/*else{
					//undo
					fsetpos(fp, &undo_pos);
					fgetpos(fp, &undo_pos);
					read = fscanf(fp, "%d%c%c%d %d%c%c%d %d%c%c%d", i[0],'/','/',n, i[1],'/','/',n, i[2],'/','/',n);
					
					//index,normal
					if(read == 4){

					}
				}*/
			}
		}
	}
	fclose(fp);

    Model model(vertices,faces);
    return model;
}

// quick and dirty bitmap loader...for 24 bit bitmaps with 1 plane only.  
// See http://www.dcs.ed.ac.uk/~mxr/gfx/2d/BMP.txt for more info.

int utils::ImageLoad(char *filename, utils::Image *image) {
	FILE *file;
	unsigned long size;                 // size of the image in bytes.
	//unsigned long i;					// standard counter.
	size_t i;					// standard counter.
	unsigned short int planes;          // number of planes in image (must be 1) 
	unsigned short int bpp;             // number of bits per pixel (must be 24)
	char temp;                          // temporary color storage for bgr-rgb conversion.

	// make sure the file is there.
	if ((file = fopen(filename, "rb"))==NULL) 
	{
		printf("File Not Found : %s\n",filename);
		return 0;
	}

	// seek through the bmp header, up to the width/height:
	fseek(file, 18, SEEK_CUR);

	// No 100% errorchecking anymore!!!

	// read the width
	image->sizeX = getint (file);
	printf("Width of %s: %lu\n", filename, image->sizeX);

	// read the height 
	image->sizeY = getint (file);
	printf("Height of %s: %lu\n", filename, image->sizeY);

	// calculate the size (assuming 24 bits or 3 bytes per pixel).
	size = image->sizeX * image->sizeY * 3;

	// read the planes
	planes = getshort(file);
	if (planes != 1) 
	{
		printf("Planes from %s is not 1: %u\n", filename, planes);
		return 0;
	}

	// read the bpp
	bpp = getshort(file);
	if (bpp != 24) 
	{
		printf("Bpp from %s is not 24: %u\n", filename, bpp);
		return 0;
	}

	// seek past the rest of the bitmap header.
	fseek(file, 24, SEEK_CUR);

	// read the data. 
	image->data = new GLubyte[size];
	if (image->data == NULL) 
	{
		printf("Error allocating memory for color-corrected image data");
		return 0;	
	}

	if ((i = fread(image->data, size, 1, file)) != 1) 
	{
		printf("Error reading image data from %s.\n", filename);
		return 0;
	}

	// reverse all of the colors. (bgr -> rgb)
	// reverse all of the colors. (bgr ->  gbr)
	for (i=0;i<size;i+=3) 
	{ 
		temp = image->data[i];
		image->data[i] = image->data[i+1];
		image->data[i+1] = temp;
	}

	// we're done.
	return 1;
}



unsigned int utils::getint(FILE *fp){
	int c, c1, c2, c3;

	// get 4 bytes
	c = getc(fp);  
	c1 = getc(fp);  
	c2 = getc(fp);  
	c3 = getc(fp);

	return ((unsigned int) c) +   
		(((unsigned int) c1) << 8) + 
		(((unsigned int) c2) << 16) +
		(((unsigned int) c3) << 24);
}

unsigned short utils::getshort(FILE* fp){
	int c, c1;

	//get 2 bytes
	c = getc(fp);  
	c1 = getc(fp);

	return ((unsigned int) c) + (((unsigned int) c1) << 8);
}



// Load Bitmaps And Convert To Textures
GLuint utils::LoadGLTexture(char *fileName) {	
	// Load Texture
	Image *image;

	// allocate space for texture
	image = new Image();
	if (image == NULL) 
	{
		printf("Error allocating space for image");
		exit(0);
	}

	//load picture from file
	if (!ImageLoad(fileName, image)){
		exit(1);
	}        
    GLuint textureId;
	// Create Texture Name and Bind it as current
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);   // 2d texture (x and y size)

	//Set Texture Parameters
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smaller than texture


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

	// Load texture into OpenGL RC!
	glTexImage2D(GL_TEXTURE_2D,		// 2D texture
				 0,					// level of detail 0 (normal)
				 3,					// 3 color components
				 image->sizeX,		// x size from image
				 image->sizeY,		// y size from image
				 0,					// border 0 (normal)
				 GL_RGB,			// rgb color data order
				 GL_UNSIGNED_BYTE,  // color componente types
				 image->data		// image data itself
				 );

    return textureId;
	////Once you load a texture is the original data still needed?
	//for (int i = 0; i < image1->sizeX; i++)
	//	for (int j=0; j < image1->sizeY*3; j++)
	//		image1->data[i*image1->sizeY*3+j] = 1;

	////If not, then should you deallocate it?
	//delete []image1->data;
	//delete image1;
};