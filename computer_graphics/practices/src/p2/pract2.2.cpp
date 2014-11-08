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

void miRaton(int boton, int estado, int x, int y)
{
    static GLintPoint corner[2];
    static int numCorners = 0; //inicia el valor a cero
    if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN)
    {
    corner[numCorners].x =x;
    corner[numCorners].y =Al-y;
    numCorners++;
                 if (numCorners ==2)
                 {
                 glBegin(GL_LINE_LOOP);
                 glVertex2i(corner[0].x,corner[0].y);
                 glVertex2i(corner[1].x,corner[0].y);
                 glVertex2i(corner[1].x,corner[1].y);
                 glVertex2i(corner[0].x,corner[1].y);
                 glEnd();
                 numCorners = 0; //vuelve a 0 la esquina
                 }
    }
    else if(boton == GLUT_RIGHT_BUTTON && estado == GLUT_DOWN) glClear(GL_COLOR_BUFFER_BIT); //limpia la ventana
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

int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(100, 250); //Posiciona la ventana en la pantalla
    glutCreateWindow("Practica 2.2:interaccion con raton");//Abre ventana en pantalla
    glutMouseFunc(miRaton);
    glutDisplayFunc(miDibujo); //Registra la función de redibujar
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}
