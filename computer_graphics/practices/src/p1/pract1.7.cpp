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
#define An 400
#define Al 400
#define GL_PI 3.14159265f

using namespace std;

void mi_Inicio(void)
{
     glClearColor(1.0f,1.0f,1.0f,0.0f); //Selecciona el color de fondo
     glColor3f(1.0f, 1.0f, 1.0f); //El color a dibujar
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, (double) An, 0.0, (double) Al);
     glPointSize(3.0);
}

void ajedrez (GLint tamanio)
{
     GLfloat r1,r2,g1,g2,b1,b2;
     r1 = 1.0 ; r2 = 0.4;
     b1 = g1 = r1; b2 = g2 = r2;
     glClear(GL_COLOR_BUFFER_BIT);
     for (GLint i=0; i <=7;i++)
         for(GLint j=0; j<=7; j++)
         {
                   if((i+j)%2 ==0) //Si i+j es par
                   glColor3f(r1, g1, b1);
                   else //Si i+j es impar
                   glColor3f(r2, g2, b2);
                   glRecti(i*tamanio,j*tamanio,i*tamanio+tamanio,j*tamanio+tamanio);
                   }
         glFlush();
}

void miDibujo(void)
{
     ajedrez(50);
}

int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(0, Al); //Posiciona la ventana en la pantalla
    glutCreateWindow("Practica 1.7:Tablero de ajedrez");//Abre ventana en pantalla
    glutDisplayFunc(miDibujo); //Registra la función de redibujar
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}
