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

int random(int m){
    return rand( )%m;
}

void miDibujo(void)
{
     glClear(GL_COLOR_BUFFER_BIT); //Limpia la pantalla
     glBegin(GL_POINTS);// para pintar la función
     glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
     glEnd();
     glFlush();
}


void mi_Inicio(void)
{
     glClearColor(1.0f,1.0f,1.0f,0.0f); //Selecciona el color de fondo
     glColor3f(1.0f, 1.0f, 1.0f); //El color a dibujar
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, (double) An, 0.0, (double) Al);
     glPointSize(3.0);
}

void dibuja_puntos(int x, int y){
     glBegin(GL_POINTS);
     glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
     glVertex2i(x,y);
     glEnd();
     glFlush();
}

void Sierpinski(GLintPoint* corners){
     GLintPoint T[3];
     glClear(GL_COLOR_BUFFER_BIT); //Limpia la pantalla
     for(int i=0;i<3;i++){
          T[i]=corners[i];
          } // Coordenadas vértices
     int index = random(3); //devuelve 0, 1, o 2
     GLintPoint point =T[index]; //inicializa los puntos
     dibuja_puntos(point.x, point.y); //dibuja punto inicial
     for(int i =0; i< 10000; i++) //dibuja 1000 puntos
     {
             index = random(3);
             point.x = (point.x + T[index].x) /2;
             point.y = (point.y + T[index].y) /2;
             dibuja_puntos(point.x, point.y);
     }
     glFlush();
}


void miRaton(int boton, int estado, int x, int y)
{
     static GLintPoint corners[3];
     static int numCorners = 0;
     if (boton ==GLUT_LEFT_BUTTON && estado == GLUT_DOWN){
        corners[numCorners].x =x;
        corners[numCorners].y =Al-y; //Para corregir el origen de coordenadas
                if(++numCorners ==3)
                {
                Sierpinski(corners); //dibuja el gráfico de Sierpinski
                numCorners = 0; //vuelve a 0 la esquina
                }
        }
     else if(boton == GLUT_RIGHT_BUTTON && estado == GLUT_DOWN)
     glClear(GL_COLOR_BUFFER_BIT); // limpia la ventana
     glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(100, 250); //Posiciona la ventana en la pantalla
    glutCreateWindow("Practica 2.3:interaccion con raton");//Abre ventana en pantalla
    glutMouseFunc(miRaton);
    glutDisplayFunc(miDibujo); //Registra la función de redibujar
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}
