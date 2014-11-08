#ifdef WIN32
#include<windows.h>
#endif
#ifdef WIN32
#include<windows.h>
#endif
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<fstream>
#ifndef WIN32
#include <iostream>
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "camara.h"

#define An 640
#define Al 480

#define GL_PI 3.14159265f

using namespace std;

GLint menuItemNumber=1;
GLint selectFcn=1;

Point3 eye, look;
Vector3 up;
Camera cam; 
int MALLADO = 1;         //1 dibuja el mallado con lineas, 0 con puntos
double DENS = 0.11025;   //densidad del mallado 
GLfloat RADP = 1.0;      //radio del cada punto

void 
myKeyboard(unsigned char key, int x, int y)
{
  extern int MALLADO;
  extern double DENS;
  extern GLfloat RADP;
  
  switch(key)
  {	
	// controles slide para camara
	case '-':    cam.slide(0,0.,0.2f); break;  //zoom -
	case '+':    cam.slide(0,0,-0.2f); break; //zoom +	
	
	// controles arriba/abajo and izquierde/derecha	
	case 's':    cam.pitch(-1.0); break; //desplazamiento abajo
	case 'w':    cam.pitch( 1.0); break; //desplazamiento arriba
	case 'd':    cam.slide(-0.2f,0,0); break; //desplazamiento derecha
	case 'a':    cam.slide(+0.2f,0,0); break; //desplazamiento izda
	// controles de cabeceo 
	case 't':    cam.roll(-1.0); break; //cabeceo derecha
	case 'r':    cam.roll( 1.0); break; //cabeceo izquierda
	
	//controles giro camara
	case 'i':    glRotatef(-1, 0.0, 0.0, 1.0);
	             break;
   	case 'j':    glRotatef(-1, 1.0, 0.0, 0.0);
	             break;
	case 'l':    glRotatef(+1, 1.0, 0.0, 0.0);
	             break;
	case 'k':    glRotatef(+1, 0.0, 0.0, 1.0);
	             break;
    case 'u':    glRotatef(-1, 1.0, 0.0, 0.0);
                 glRotatef(-1, 0.0, 0.0, 1.0);
	             break;
    case 'o':    glRotatef(-1, 0.0, 0.0, 1.0);
                 glRotatef(+1, 1.0, 0.0, 0.0);
                 break;
    case 'm':    glRotatef(-1, 1.0, 0.0, 0.0);
                 glRotatef(+1, 0.0, 0.0, 1.0);
                 break;
    case '.':    glRotatef(+1, 1.0, 0.0, 0.0);   
                 glRotatef(+1, 0.0, 0.0, 1.0);
                 break;        
    
    //Controles dibujado
    case '1':    MALLADO = 1;
                 break;   
    case '2':    MALLADO = 0;
                 break;  
    case 'x':    DENS /=1.05;
                 break;    
    case 'z':    DENS *=1.05;
                 break;
    case 'c':    if(RADP>1) RADP-=0.1;
                 break;
    case 'v':    RADP += 0.1;
                 break;
  }

  glutPostRedisplay(); // dibuja de nuevo
}


void 
dibujo(void){
     long long int i,j;
     double u,v;
     double x,y,z;
     extern double DENS;
     long long int filas, columnas;
     extern int MALLADO;
     extern GLfloat RADP;

     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     if(MALLADO == 1)
       glBegin(GL_LINES);
     else{
       glEnable(GL_POINT_SMOOTH);
       glPointSize(RADP);
       glBegin(GL_POINTS);
     }    
     
     switch (selectFcn){
            
     case 1:
          glColor3f(0.0,0.0,1.0);     
          for(u=-GL_PI;u<GL_PI;u+=DENS){
            for(v=-GL_PI;v<GL_PI;v+=DENS){
              glVertex3f(2*cos(v)*cos(u),cos(v)*sin(u),sin(v)); 
              glVertex3f(2*cos(v-DENS)*cos(u),cos(v-DENS)*sin(u),sin(v-DENS)); 
            }
          }  
          for(u=-GL_PI;u<GL_PI;u+=DENS){
            for(v=-GL_PI;v<GL_PI;v+=DENS){
              glVertex3f(2*cos(v)*cos(u),cos(v)*sin(u),sin(v)); 
              glVertex3f(2*cos(v)*cos(u-DENS),cos(v)*sin(u-DENS),sin(v)); 
            }
          }
          glEnd();
          glutSwapBuffers();
          break;
     
     case 2:
          glColor3f(0.0,0.0,1.0);
          for(u=-2;u<2;u+=DENS){
              for(v=0;v<2*GL_PI;v+=DENS){
                  glVertex3f(cos(v)*cosh(u),sin(v)*cosh(u),sinh(u));
                  glVertex3f(cos(v-DENS)*cosh(u),sin(v-DENS)*cosh(u),sinh(u));
              }
          }
          for(u=-2;u<2;u+=DENS){
              for(v=0;v<2*GL_PI;v+=DENS){
                  glVertex3f(cos(v)*cosh(u),sin(v)*cosh(u),sinh(u));
                  glVertex3f(cos(v)*cosh(u-DENS),sin(v)*cosh(u-DENS),sinh(u-DENS));
              }
          }
          glEnd();
          glutSwapBuffers();
          break;
     
     case 3:
          glColor3f(0.0,0.0,1.0);
          for(u=0;u<2;u+=DENS){
              for(v=0;v<2*GL_PI;v+=DENS){
                  glVertex3f(cos(v)*sinh(u),sin(v)*sinh(u),cosh(u));
                  glVertex3f(cos(v-DENS)*sinh(u),sin(v-DENS)*sinh(u),cosh(u));
              }
          }
          
          for(u=0;u<2;u+=DENS){
              for(v=0;v<2*GL_PI;v+=DENS){
                  glVertex3f(cos(v)*sinh(u),sin(v)*sinh(u),cosh(u));
                  glVertex3f(cos(v)*sinh(u-DENS),sin(v)*sinh(u-DENS),cosh(u-DENS));
              }
          } 
          //2a hoja
          for(u=-2;u<0;u+=DENS){
              for(v=0;v<2*GL_PI;v+=DENS){
                  glVertex3f(cos(v)*sinh(u),sin(v)*sinh(u),-cosh(u));
                  glVertex3f(cos(v-DENS)*sinh(u),sin(v-DENS)*sinh(u),-cosh(u));
              }
          }

          for(u=-2;u<0;u+=DENS){
              for(v=0;v<2*GL_PI;v+=DENS){
                  glVertex3f(cos(v)*sinh(u),sin(v)*sinh(u),-cosh(u));
                  glVertex3f(cos(v)*sinh(u-DENS),sin(v)*sinh(u-DENS),-cosh(u-DENS));
              }
          }
          glEnd();
          glutSwapBuffers();
          break;
     
     case 4:
          glColor3f(0.0,0.0,1.0);
          for(u=-GL_PI;u<GL_PI;u+=DENS){
              for(v=-GL_PI;v<GL_PI;v+=DENS){
                  glVertex3f(v*cos(u),v*sin(u),v);
                  glVertex3f((v-DENS)*cos(u),(v-DENS)*sin(u),(v-DENS));
              }
          } 

          for(u=-GL_PI;u<GL_PI;u+=DENS){
              for(v=-GL_PI;v<GL_PI;v+=DENS){
                  glVertex3f(v*cos(u),v*sin(u),v);
                  glVertex3f(v*cos(u-DENS),v*sin(u-DENS),v);
              }
          } 
          glEnd();
          glutSwapBuffers();
          break;
     
      case 5:
          glColor3f(0.0,0.0,1.0);
          for(u=-GL_PI;u<GL_PI;u+=DENS){
              for(v=0;v<2*GL_PI;v+=DENS){
                  glVertex3f(v*cos(u),v*sin(u),v*v);
                  glVertex3f((v-DENS)*cos(u),(v-DENS)*sin(u),(v-DENS)*(v-DENS));
              }
          } 

          for(u=-GL_PI;u<GL_PI;u+=DENS){
              for(v=0;v<2*GL_PI;v+=DENS){
                  glVertex3f(v*cos(u),v*sin(u),v*v);
                  glVertex3f(v*cos(u-DENS),v*sin(u-DENS),v*v);
              }
          } 
          glEnd();
          glutSwapBuffers();
          break;
      
      case 6:
          //Intervalo 1
          glColor3f(0.0,0.0,1.0);
          for(u=-GL_PI;u<-GL_PI/1.8;u+=DENS){
              for(v=-3;v<GL_PI;v+=DENS){
                  glVertex3f(v*tan(u),v/cos(u),v*v);
                  glVertex3f((v-DENS)*tan(u),(v-DENS)/cos(u),(v-DENS)*(v-DENS));
              }
          } 

          for(u=-GL_PI;u<-GL_PI/1.8;u+=DENS){
              for(v=0;v<GL_PI;v+=DENS){
                  glVertex3f(v*tan(u),v/cos(u),v*v);
                  glVertex3f(v*tan(u-DENS),v/cos(u-DENS),v*v);
              }
          } 
          //Intervalo 2
          for(u=-GL_PI/2.2;u<GL_PI/2.2;u+=DENS){
              for(v=0;v<GL_PI;v+=DENS){
                  glVertex3f(v*tan(u),v/cos(u),v*v);
                  glVertex3f((v-DENS)*tan(u),(v-DENS)/cos(u),(v-DENS)*(v-DENS));
              }
          } 

          for(u=-GL_PI/2.2;u<GL_PI/2.2;u+=DENS){
              for(v=0;v<GL_PI;v+=DENS){
                  glVertex3f(v*tan(u),v/cos(u),v*v);
                  glVertex3f(v*tan(u-DENS),v/cos(u-DENS),v*v);
              }
          }          
          
          //Intervalo 3
          for(u=GL_PI/1.8;u<GL_PI;u+=DENS){
              for(v=0;v<GL_PI;v+=DENS){
                  glVertex3f(v*tan(u),v/cos(u),v*v);
                  glVertex3f((v-DENS)*tan(u),(v-DENS)/cos(u),(v-DENS)*(v-DENS));
              }
          } 

          for(u=GL_PI/1.8;u<GL_PI;u+=DENS){
              for(v=0;v<GL_PI;v+=DENS){
                  glVertex3f(v*tan(u),v/cos(u),v*v);
                  glVertex3f(v*tan(u-DENS),v/cos(u-DENS),v*v);
              }
          } 
          
          glEnd();
          glutSwapBuffers();
          break;
     } 
     
}


void 
menuFcn (GLint menuItemNumber){
     switch (menuItemNumber) {
            case 1: selectFcn=1; break;//Registra la función de redibujar
            case 2: selectFcn=2; break;//Registra la función de redibujar
            case 3: selectFcn=3; break;//Registra la función de redibujar
            case 4: selectFcn=4; break;//Registra la función de redibujar
            case 5: selectFcn=5; break;//Registra la función de redibujar
            case 6: selectFcn=6; break;//Registra la función de redibujar
            }
     glutPostRedisplay ();
}


int 
main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // doble buffers
	glutInitWindowSize(640,480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Representacion de curvas parametricas en 3D");
	glutKeyboardFunc(myKeyboard);
	glutDisplayFunc(dibujo);
	glClearColor(1.0f,1.0f,1.0f,1.0f);  // fondeo blanco 
	glColor3f(0.0f,1.0f,1.0f);			// asigna el color  
	glViewport(0, 0, 640, 480);
	eye.x=5;eye.y=5;eye.z=2;
	look.x=0;look.y=0;look.z=0;
	up.x=0;up.y=1;up.z=0;
	cam.set(eye,look,up);
	cam.setShape(30.0f, 64.0f/48.0f, 0.5f, 50.0f);
	cam.slide(0,0, 0.0f);
	glutCreateMenu(menuFcn);
    glutAddMenuEntry ("Elipsoide",1);
    glutAddMenuEntry ("Hiperboloide de una hoja",2);
    glutAddMenuEntry ("Hiperboloide de dos hojas",3);
    glutAddMenuEntry ("Cono eliptico",4);
    glutAddMenuEntry ("Paraboloide eliptico",5);
    glutAddMenuEntry ("Paraboloide hiperbolico",6);
    glutAttachMenu (GLUT_RIGHT_BUTTON);
	glutMainLoop();
}
