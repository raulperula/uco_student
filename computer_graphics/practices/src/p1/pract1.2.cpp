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
#define An 640
#define Al 480
#define GL_PI 3.14159265f

using namespace std;

void mi_Inicio(void)
{
     glClearColor(0.489f,0.397f,0.123f,0.0f); //Selecciona el color de fondo
     glColor3f(1.0f, 1.0f, 1.0f); //El color a dibujar
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, (double) An, 0.0, (double) Al);
}


void miDibujo(void)
{
     
     double Sx,Sy;
     glClear(GL_COLOR_BUFFER_BIT); //Limpia la pantalla
     glBegin(GL_POINTS);// para pintar la función
     glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
     for (GLdouble x =0; x < 4.0 ; x += 0.0001)
         {
                   GLdouble y = exp(-x) * cos(2*GL_PI * x);
                   Sx = (An/4.0)*x;
                   Sy = (Al/3.0)*y + (Al*1.5)/3.0;
                   glVertex2d(Sx, Sy);
         }
     glEnd();
     glFlush();
     glBegin(GL_LINE_STRIP);//para pintar el eje
     glColor3f(1.0f, 1.0f, 0.0f); //El color a dibujar
     glVertex2d(0, Al/2);
     glVertex2d(An, Al/2);
     glEnd();
     glFlush();
}


int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(200, 350); //Posiciona la ventana en la pantalla
    glutCreateWindow("Mi primer trabajo en OpenGL");//Abre ventana en pantalla
    glutDisplayFunc(miDibujo); //Registra la función de redibujar
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}

