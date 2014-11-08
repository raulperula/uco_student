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
#include <stdio.h>
#define An 640
#define Al 480
#define GL_PI 3.14159265f
#define R 1.333333f

using namespace std;

void setWindow(float left,float right,float bottom,float top){
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(left,right,bottom,top);
     }

void setViewport(int left,int right,int bottom,int top){
     glViewport(left,bottom,right-left,top-bottom);
}


void mi_Inicio(void)
{
     glClearColor(1.0f,1.0f,1.0f,0.0f); //Selecciona el color de fondo
     glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
     setWindow(0.0, 640.0,0.0,480.0);
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, (double) An, 0.0, (double) Al);
     glPointSize(3.0);
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

void reDimension(GLsizei W, GLsizei H)
{
     if (R > W/H) //usa la relación de aspecto global
     setViewport(0, W, 0, W/R);
     else setViewport(0, H*R, 0, H);
}

void miDibujo(void){
    char * archivo;
    archivo= "dino.dat";
    glClear(GL_COLOR_BUFFER_BIT); //Limpia la pantalla
    drawPolyLineFile(archivo);
}

int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(100, 250); //Posiciona la ventana en la pantalla
    glutCreateWindow("Practica 3.6: Redimension");//Abre ventana en pantalla
    glutDisplayFunc(miDibujo); //Registra la función de redibujar
    glutReshapeFunc(reDimension); //Redimension cuando es necesario
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}
