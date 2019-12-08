//header

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <variant>
#include <stdlib.h>

#include "Vertex.h"
#include "Face.h"
#include "utils.h"
#include "Scene.h"
#include "GraphicsEngine.h"

//globals
float elephantrot;
int w=-100;
int a=0;
Model model;
Model floorModel;
Scene scene;
GLuint textureId;
extern std::vector<GLuint*> textureIds;
extern std::map<std::string, GLuint*> textures;

void keyboard(unsigned char key, int x, int y) ;

void reshape(int w,int h){    
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);
	//glOrtho(-25,25,-2,2,0.1,100);	
	glMatrixMode(GL_MODELVIEW);
}

void drawCar(){
 	glPushMatrix();
		// glTranslatef(0,-40.00,-105);
		glTranslatef(a,0,w);
		//glColor3f(1.0,0.23,0.27);
		// glScalef(0.1,0.1,0.1);
		glRotatef(elephantrot,0,1,0);
		
		// model.render();
		scene.render();
 	glPopMatrix();
	glutPostRedisplay();
 	elephantrot=elephantrot+0.6;
 	if(elephantrot>360)elephantrot=elephantrot-360;
}

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
	GLfloat aspect;
	// textureIds.push_back(utils::LoadGLTexture("data/Abstract3_512.bmp", "Abstract")); 
	// textureIds.push_back(utils::LoadGLTexture("data/floor_checkerboard.bmp", "floor")); 
	// textureIds.push_back(utils::LoadGLTexture("data/Crate.bmp", "crate")); 
					// Enable Texture Mapping
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);	// Clear The Background Color To Blue 
	glClearDepth(1.0);						// Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS);					// The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);				// Enables Depth Testing
	glShadeModel(GL_SMOOTH);				// Enables Smooth Color Shading

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();						// Reset The Projection Matrix

	aspect = (GLfloat)Width/(GLfloat)Height;	// Calculate The Aspect Ratio Of The Window
	gluPerspective(60.0f,aspect,0.1f,1000.0f);	// Set Projection matrix

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();						// Reset The View
	glTranslatef(0.0f,0.0f,-20.0f);          // Establish View Matrix

}

void display(void){  
   	glClearColor (0.0,0.0,0.0,1.0); 
   	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   	glLoadIdentity();
   	drawCar();
   	glutSwapBuffers(); //swap the buffers

}

int main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(800,450);
	glutInitWindowPosition(20,20);
	glutCreateWindow("ObjLoader");
	glutReshapeFunc(reshape);
	
		/* Register the function called when the keyboard is pressed. */
	glutKeyboardFunc(&keyboard);
	/* Initialize our window. */
	InitGL(640, 480);
	
	// model = utils::loadObj("data/porsche.obj");//replace porsche.obj with radar.obj or any other .obj to display it
	// model.serialize();
	// model.useTexture("Abstract");
	// // scene.Add(&model);

	
	// floorModel = utils::loadObj("data/Map_Dust2.obj");
	// // floorModel = utils::loadObj("data/cube.obj");
	// floorModel.serialize();
	// floorModel.useTexture("floor");
	// // floor.useTexture(-1,false);
	// scene.Add(&floorModel);
	
	// Model cube = utils::loadObj("data/cube.obj");
	// cube.useTexture("crate");
	// scene.Add(&cube);
	scene.LoadScene("data/Scene.xml");


	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
	return 0;
}

void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'a':
		a++;
		break;
	case 'd':
		a--;
		break;
	case 'w':
		w++;
		break;
	case 's':
		w--;
		break;
	case 27:
		// shut down our window 
		//glutDestroyWindow(window);
		// exit the program...normal termination.
		exit(0);
	
	}
	Log(w);
	Log(a);
}
