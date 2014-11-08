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
     glEnable(GL_LINE_STIPPLE);
}


void dibuja_Puntos(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}

void miDibujo(void)
{
     glClear(GL_COLOR_BUFFER_BIT); //Limpia la pantalla
     glBegin(GL_POINTS);// para pintar la función
     glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
     glEnd();
     glFlush();
}
void mi_Raton(int boton, int estado, int x, int y)
{
  if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) dibuja_Puntos(x, Al-y);
  else if (boton == GLUT_RIGHT_BUTTON && estado == GLUT_DOWN)
  glClear(GL_COLOR_BUFFER_BIT);
}



int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(100, 250); //Posiciona la ventana en la pantalla
    glutCreateWindow("Practica 2.1:interaccion con raton");//Abre ventana en pantalla
    glutMouseFunc(mi_Raton);
    glutDisplayFunc(miDibujo); //Registra la función de redibujar
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}
