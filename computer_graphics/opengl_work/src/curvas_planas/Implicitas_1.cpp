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

void miDibujo(void){
//Dibuja la función
     glClear(GL_COLOR_BUFFER_BIT);
     setWindow(-10, 10, -10, 10);
     setViewport(0,An,0,Al);
     glBegin(GL_LINE_STRIP);
     for(GLdouble x =-10; x < 10; x += 0.01){
         GLfloat y =(2*x-5)/(x-1);
         glVertex2f(x,y);
         }
     glEnd();
     glFlush();
     //dibuja eje x
     glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f); //El color a dibujar
     glVertex2d(-10,0);
     glVertex2d(10,0);
     glEnd();
     //dibuja eje y
     glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f); //El color a dibujar
     glVertex2d(0,10);
     glVertex2d(0,-10);
     glEnd();
     glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(100, 250); //Posiciona la ventana en la pantalla
    glutCreateWindow("Representacion de curvas a partir de la ecuacion implícita");//Abre ventana en pantalla
    glutDisplayFunc(miDibujo); //Registra la función de redibujar
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}
