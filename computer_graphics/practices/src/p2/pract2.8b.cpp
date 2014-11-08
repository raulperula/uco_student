#ifdef WIN32
#include<windows.h>
#endif
#include<GL/gl.h>
#include<GL/glut.h>
#include<fstream>
#include <iostream>
#include<stdio.h>
#include <math.h>


#define An 400
#define Al 400
#define NUM 20

using namespace std;

class GLintPoint{
public:
GLint x,y;
};


void miDibujo(void)
{
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0,0.0,0.6); //Color de las barras Rojo
     glPointSize(3.0);
     glFlush();
}

void mi_Inicio(void)
{
     glClearColor(1.0,1.0,1.0,0.0); //Selecciona el color de fondo
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, (double) An, 0.0, (double) Al);
}


void parameterizedHouse(GLint X2, GLint Y2, GLint L, GLint H)
{
     glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_LINE_LOOP);


//----------------------------------------------------
// dibuja la casa
     glVertex2i( X2, Y2);
     glVertex2d( X2-L/2,Y2-0.375*H);
     glVertex2d( X2-L/2, Y2-H);
     glVertex2d( X2+L/2,Y2-H);
     glVertex2d( X2+L/2,Y2-0.375*H);
     glEnd();


//---------------------------------------------------
// dibuja la puerta
     GLint X1 = X2-L/2;
     GLint Y1 = Y2 - H;
     glBegin(GL_LINE_STRIP);
     glVertex2d(X1+0.12*L,Y1);
     glVertex2d(X1+0.12*L,Y1+0.4*H);
     glVertex2d(X1+0.12*L+0.25*L,Y1+0.4*H);
     glVertex2d(X1+0.12*L+0.25*L,Y1);
     glEnd();


//----------------------------------------------------------
// dibuja la ventana
     GLdouble x1 = X1 + 0.75*L;
     GLdouble y1 = Y1 + 0.3*H;
     GLdouble anch_Vent = 0.125*L;
     glBegin(GL_LINE_LOOP);
     glVertex2d(x1, y1);
     glVertex2d(x1 + anch_Vent,y1 );
     glVertex2d(x1 + anch_Vent,y1 + anch_Vent);
     glVertex2d(x1, y1 + anch_Vent );
     glEnd();
}


void miRaton(int boton, int estado, int x, int y)
{
    static GLintPoint points[2];
    static int numPoints = 0; //inicia el valor a cero
    GLint L,H;
    GLintPoint aux;
    if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN){
       points[numPoints].x =x;
       points[numPoints].y =Al-y;
       numPoints++;
       if (numPoints==2){
          if(points[1].y<points[0].y){
              aux.x=points[1].x;
              aux.y=points[1].y;
              points[1].x=points[0].x;
              points[1].y=points[0].y;
              points[0].x=aux.x;
              points[0].y=aux.y;
              }
          parameterizedHouse(points[1].x,points[1].y,2*(points[1].x-points[0].x),points[1].y-points[0].y);
          numPoints = 0;
          }
       }
    else if(boton == GLUT_RIGHT_BUTTON && estado == GLUT_DOWN)
    glClear(GL_COLOR_BUFFER_BIT); //limpia la ventana
    glFlush();
}


 	

int main(int argc, char* argv[])
{
glutInit(&argc, argv); //Inicializa toolkit
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
glutInitWindowPosition(100, 150); //Posiciona la ventana en la pantalla
glutCreateWindow("Practica 2.8: Parametrizacion de figuras");//Abre ventana en pantalla
mi_Inicio();
glutDisplayFunc(miDibujo); //Registra la función de redibujar
glutMouseFunc(miRaton);
glutMainLoop(); //Bucle continuo

return 0;
}
