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
     glEnable(GL_LINE_STIPPLE);
}

void miDibujo(void)
{
     glClear(GL_COLOR_BUFFER_BIT); //Limpia la pantalla
     glBegin(GL_POINTS);// para pintar la función
     glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
     glEnd();
     glFlush();
}

void miRaton(int boton, int estado, int x, int y)
{ 
     static GLintPoint List[NUM];
     static int last = -1; //inicializa el índice para utilizar
     //Test para el botón del ratón y para rellenar la matriz
     if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && last < (NUM -1))
     { 
          List[++last].x =x;
          List[ last].y =Al - y;
          glClear(GL_COLOR_BUFFER_BIT); //limpia la pantalla
          glBegin(GL_LINE_STRIP);
          for (int i =0; i<= last; i++) glVertex2i(List[i].x,List[i].y);
          glEnd();
          glFlush();
          }
     else if(boton == GLUT_RIGHT_BUTTON &&estado == GLUT_DOWN)
     {
          last = -1; //resetea la lista para vaciarla
          glClear(GL_COLOR_BUFFER_BIT); //limpia la pantalla
          }
}

int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(100, 250); //Posiciona la ventana en la pantalla
    glutCreateWindow("Practica 2.4:interaccion con raton");//Abre ventana en pantalla
    glutMouseFunc(miRaton);
    glutDisplayFunc(miDibujo); //Registra la función de redibujar
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}
