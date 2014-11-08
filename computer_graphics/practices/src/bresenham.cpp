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
}

void dibuja_punto(int x, int y){
     glPointSize(2.0);
     glBegin(GL_POINTS);
     glColor3f(0.0f, 1.0f, 0.0f); //El color a dibujar
     glVertex2i(x,y);
     glEnd();
     glFlush();
}

void dibuja_puntoIF(int x, int y){
     glPointSize(6.0);
     glBegin(GL_POINTS);
     glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
     glVertex2i(x,y);
     glEnd();
     glFlush();
}


void bresenham(int x1,int y1,int x2,int y2)
{
   //calcular incrementos para el caso tramo diagonal(dxd,dyd)
   int dxd,dyd,dxr,dyr,x,y,E,Ed,Er,i,incx,incy;
   int dx=1;
   int dy=1;
   incy = y2 - y1;
   if(incy<0)
   {
      dy = - dy;
      incy= - incy;
   }
   dyd=dy;
   incx=x2 - x1;
   if(incx<0)
   {
      dx= - dx;
      incx= - incx;
   }
   dxd=dx;
   //cálculo de los incrementos para el caso tramo recto(dxr,dyr)
   if(incx>=incy)
   {
   	dy=0;
   }
   else
   {
   	  dx=0;
      x=incx;
      incx=incy;
      incy=x;
   }
   dyr=dy;
   dxr=dx;
   //valores iniciales
   x=x1;
   y=y1;
   Er=2*incy;
   Ed=2*incy - 2*incx;
   E=2*incy - incx;
   //dibujar la recta
   for(i=0;i<(incx-1);i++)
   {
      dibuja_punto(x,y);
      if(E>=0)
      {
         x=x + dxd;
         y=y + dyd;
         E=E + Ed;
      }
      else
      {
      	 x=x + dxr;
         y=y + dyr;
         E=E + Er;
      }
   }
}

void miRaton(int boton, int estado, int x, int y)
{
     static GLintPoint corners[2];
     static int numCorners = 0;
     if (boton ==GLUT_LEFT_BUTTON && estado == GLUT_DOWN){
        corners[numCorners].x =x;
        corners[numCorners].y =Al-y; //Para corregir el origen de coordenadas
                if(++numCorners ==2)
                {
                bresenham(corners[0].x,corners[0].y,corners[1].x,corners[1].y); //dibuja el gráfico de Sierpinski
                dibuja_puntoIF(corners[0].x,corners[0].y);
                dibuja_puntoIF(corners[1].x,corners[1].y);
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
