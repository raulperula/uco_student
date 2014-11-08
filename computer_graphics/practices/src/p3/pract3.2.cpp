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
#define An 640
#define Al 480
#define GL_PI 3.14159265f

using namespace std;

void mi_Inicio(void)
{
     glClearColor(1.0f,1.0f,1.0f,0.0f); //Selecciona el color de fondo
     glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, (double) An, 0.0, (double) Al);
     glPointSize(3.0);
}

void setWindow(float left,float right,float bottom,float top){
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(left,right,bottom,top);
     }

void setViewport(int left,int right,int bottom,int top){
     glViewport(left,bottom,right-left,top-bottom);
     }
     
void drawPolyLineFile(char* archivo){
     int i,j;
     fstream entrada;
     entrada.open(archivo,ios ::in); //abre el archivo    
     if(entrada.fail()) return;
    
     GLint numpolys, numLineas, x, y;
     entrada >> numpolys;
     for(j=0;j<numpolys;j++){
                             entrada >> numLineas;
                             glBegin(GL_LINE_STRIP);
                             glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
                             for(i=0;i<numLineas;i++){
                                                      entrada >>x >> y;
                                                      glVertex2i(x,y);
                                                      }
                                                      glEnd();
                             }
                             glFlush();
     entrada.close();
}

void miDibujo(void){
     glClear(GL_COLOR_BUFFER_BIT); // limpia la pantalla
     setWindow(0,640.0,0,480.0);
     for(int i=0; i< 5; i++){
             for(int j=0;j<5;j++){
                     glViewport(i*128,j*96,128,96);
                     drawPolyLineFile("dino.dat");
                     }
     }
}

int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(200, 250); //Posiciona la ventana en la pantalla
    glutCreateWindow("Practica 3.2: Puerto de vista y polilineas de archivo");//Abre ventana en pantalla
    glutDisplayFunc(miDibujo); //Registra la función de redibujar
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}
