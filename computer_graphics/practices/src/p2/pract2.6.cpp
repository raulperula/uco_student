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

void dibuja_Puntos(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}

void miTeclado(unsigned char tecla,int RatonX,int RatonY )
{
     static GLintPoint List[NUM];
     static int last = -1;
     GLint x = RatonX; //Graba la posición del ratón
     GLint y = Al - RatonY; //Cambio de referencia
     switch(tecla){
     case 'p': dibuja_Puntos(x,y); // Dibuja un punto en la posición del ratón
               break;
     case 'l': List[++last].x = x; //añade un punto
               List[ last].y = y;
               glClear(GL_COLOR_BUFFER_BIT);
               glBegin(GL_LINE_STRIP);
               glVertex2i(0,0);
               glVertex2i(List[last].x,List[last].y);
               glEnd();
               glFlush();
               break;
     case 'S': exit(-1); //Termina el programa
     default:
             break; //No hace nada
     }
}

int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(100, 250); //Posiciona la ventana en la pantalla
    glutCreateWindow("Practica 2.6:interaccion con raton y teclado");//Abre ventana en pantalla
    glutDisplayFunc(miDibujo); //Registra la función de redibujar
    glutKeyboardFunc(miTeclado);
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}
