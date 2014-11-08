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
#define NUM 20

using namespace std;

class GLintPoint{
  public:
    GLint x,y;
};

void mi_Inicio(void)
{
     glClearColor(1.0f,1.0f,1.0f,0.0f); //Selecciona el color de fondo
     glColor3f(1.0f, 1.0f, 1.0f); //El color a dibujar
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, (double) An, 0.0, (double) Al);
     glPointSize(3.0);
}

void miDibujo(void)
{
     glClear(GL_COLOR_BUFFER_BIT); //Limpia la pantalla
     glBegin(GL_POINTS);// para pintar la función
     glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
     glEnd();
     glFlush();
}

void MoverRaton(int RatonX, int RatonY)
{
     GLint x = RatonX; //Graba la posicín del ratón
     GLint y = Al - RatonY; //Cambio de referencia
     GLint brushSize = 5; //Tamaño de la brocha
     glRecti(x,y, x+brushSize,y+brushSize);
     glFlush();
}

void dibuja_Puntos(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}


void mi_Raton(int boton, int estado, int x, int y)
{
     if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN)
     dibuja_Puntos(x, Al-y);
     else if (boton == GLUT_RIGHT_BUTTON && estado == GLUT_DOWN)
     glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(100, 250); //Posiciona la ventana en la pantalla
    glutCreateWindow("Practica 2.5:interaccion con raton");//Abre ventana en pantalla
    glutMouseFunc(mi_Raton);//registra la funcion del raton
    glutDisplayFunc(miDibujo); //Registra la función de redibujar
    glutMotionFunc(MoverRaton);//registra el movimiento del raton
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}
