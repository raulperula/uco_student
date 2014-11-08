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

GLintPoint aux[2];
int numPoints=0;

void miDibujo(void)
{
     glClear(GL_COLOR_BUFFER_BIT); //Limpia la pantalla
     glBegin(GL_POINTS);// para pintar la función
     glColor3f(1.0f, 1.0f, 0.0f); //El color a dibujar
     glEnd();
     glFlush();
}

void mi_Inicio(void)
{
     glClearColor(1.0f,1.0f,1.0f,0.0f); //Selecciona el color de fondo
     glColor3f(1.0f, 0.0f, 1.0f); //El color a dibujar
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, (double) An, 0.0, (double) Al);
     glPointSize(3.0);
}

void parameterizedHouse(GLint X1, GLint Y1, GLint X2, GLint Y2)
{
   GLint L=2*(X2-X1);
   GLint H=Y2-Y1;
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0f, 1.0f, 0.0f); //El color a dibujar
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
//GLint X1 = X2-L/2;
//GLint Y1 = Y2 - H;
   glBegin(GL_LINE_STRIP);
   glVertex2d(X1+0.12*L,Y1);
   glVertex2d(X1+0.12*L,Y1+0.4*H);
   glVertex2d(X1+0.12*L+0.25*L,Y1+0.4*H);
   glVertex2d(X1+0.12*L+0.25*L,Y1);
   glEnd();
//----------------------------------------------------------
// dibuja la ventana
   double x1 = X1 + 0.75*L;
   double y1 = Y1 + 0.3*H;
   double anch_Vent = 0.125*L;
   glBegin(GL_LINE_LOOP);
   glVertex2d(x1, y1);
   glVertex2d(x1 + anch_Vent,y1 );
   glVertex2d(x1 + anch_Vent,y1 + anch_Vent);
   glVertex2d(x1, y1 + anch_Vent );
   glEnd();
}


void mi_Raton(int boton, int estado, int x, int y)
{
     extern GLintPoint aux[2];
     extern int numPoints;
     if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN){
               aux[numPoints].x=x;
               aux[numPoints].y=Al-y;
               numPoints++;
               if(numPoints==2) {parameterizedHouse(aux[0].x, aux[0].y,aux[1].x, aux[1].y);numPoints=0;}
               }
     else if (boton == GLUT_RIGHT_BUTTON && estado == GLUT_DOWN)
     glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(100, 250); //Posiciona la ventana en la pantalla
    glutCreateWindow("Practica 2.8:Parametrizacion de figuras");//Abre ventana en pantalla
    glutMouseFunc(mi_Raton);
    glutDisplayFunc(miDibujo); //Registra la función de redibujar
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}
