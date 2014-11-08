#ifdef WIN32
#include<windows.h>
#endif
#ifdef WIN32
#include<windows.h>
#endif
#include<GL/gl.h>
#include<GL/glut.h>
#include<fstream>
#ifndef WIN32
#include <iostream>
#endif
#include <math.h>
#include <stdlib.h>
#include "camara.h"
#define An 640
#define Al 480
#define GL_PI 3.14159265f
#define U_MIN -GL_PI
#define U_MAX GL_PI
#define V_MIN -GL_PI/2
#define V_MAX GL_PI/2


using namespace std;

Point3 eye, look;
Vector3 up;
Camera cam; 

 
void myKeyboard(unsigned char key, int x, int y)
{
  switch(key)
  {	
	// controles para camera
	case 'l':    cam.slide(0,0, 0.2f); break; // slide camera adelante
	case 'c':    cam.slide(0,0,-0.2f); break; //slide camera atrás	
	// controles arriba/abajo and izquierde/derecha	
	case 'b':    cam.pitch(-1.0); break;
	case 's':    cam.pitch( 1.0); break;
	// controles de roll 
	case 'r':    cam.roll(-1.0); break;
	case 'R':    cam.roll( 1.0); break;
	// añadir los controles de yaw 
	case 'y':    cam.yaw(-1.0); break;
	case 'Y':    cam.yaw( 1.0); break;
  }
	glutPostRedisplay(); // dibuha de nuevo
}

void dibujo(void){
     int i,j;
     double u,v;
     double x,y,z;
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     glBegin(GLU_LINE);
     for(i=U_MIN;i<U_MAX;i+=0.5){
           for(j=V_MIN;j<V_MAX;j+=0.5){
                glVertex3f(cos(v)*cos(u),cos(v)*sin(u),sin(v)*sin(u));
                glEnd();
                }
           } 
     glutSwapBuffers();
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // doble buffers
	glutInitWindowSize(640,480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("cerca'c' lejos'l' sube's' baja'b' inclinar 'r' y 'R'cabezada 'y' 'Y'");
	glutKeyboardFunc(myKeyboard);
	glutDisplayFunc(dibujo);
	glClearColor(1.0f,1.0f,1.0f,1.0f);  // fondeo blanco 
	glColor3f(0.0f,0.0f,0.0f);			// asigna el color  
	glViewport(0, 0, 640, 480);
	eye.x=4; eye.y=4;eye.z=4;
	look.x=0;look.y=0;look.z=0;
	up.x=0;up.y=1;up.z=0;
	//cam.set(4,4,4,0,0,0,0,1,0); // crea la camera inicial 
	cam.set(eye,look,up);
	cam.setShape(30.0f, 64.0f/48.0f, 0.5f, 50.0f);
	cam.slide(0,0, 0.0f);
	glutMainLoop();
}
