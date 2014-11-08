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
     glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
     glPointSize(3.0);
}

void miDibujo(void)
{
     GLfloat y; // coordenada Y
     GLint factor = 1; // factor de línea
     GLushort pattern = 0x5555; // Tipo de Patrón
     glClear(GL_COLOR_BUFFER_BIT); // Limpia la ventana con el color actual
     glEnable(GL_LINE_STIPPLE);
     for (y = -90.0f; y < 90.0f; y += 20.0f) // incrementa 20 en y
     {
            glLineStipple(factor,pattern); //Inicializa el patrón
            glBegin(GL_LINES); // Dibuja las líneas
            glVertex2f(-80.0f, y);
            glVertex2f( 80.0f, y);
            glEnd();
            factor++;
            }
     glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(250, 150); //Posiciona la ventana en la pantalla
    glutCreateWindow("Practica 1.8:Patrones de Lineas");//Abre ventana en pantalla
    glutDisplayFunc(miDibujo); //Registra la función de redibujar
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}
