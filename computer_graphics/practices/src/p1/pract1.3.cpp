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
     glClearColor(1.0f,1.0f,1.0f,0.0f); //Selecciona el color de fondo
     glColor3f(1.0f, 1.0f, 1.0f); //El color a dibujar
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, (double) An, 0.0, (double) Al);
}


void miDibujo(void)
{

     GLdouble x,y,A,B,C,D;
     float Wr,Wl,Wt,Wb,Sx,Sy;
     int Vr,Vl,Vt,Vb;
     Vl =0; Vr = 640; Vb = 0; Vt = 480; Wr = 300.0; Wl =0.0; Wb = 225.0; Wt = 450.0;
// Calculo de los parámetros de la transformación lineal
     A = An/(Wr-Wl);
     C = Vl - A*Wl;
     B = Al/(Wt-Wb);
     D = Vb - B*Wb;
     glClear(GL_COLOR_BUFFER_BIT); //Limpia la pantalla
     glBegin(GL_LINE_STRIP);//para pintar la función
     glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
     for(x=0;x<=300.0;x += 3.0) {
                        y = 300 -100*cos((2*GL_PI*x)/100.0) + 30*cos((4*GL_PI*x)/100.0)+ 6*cos((6*GL_PI*x)/100.0);
                        Sx = A*x + C;
                        Sy = B*y + D;
                        glVertex2d(Sx,Sy);
                        
                        }
     glEnd();
     glFlush();
     glBegin(GL_LINES);//para pintar el eje
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
    glutInitWindowPosition(100, 250); //Posiciona la ventana en la pantalla
    glutCreateWindow("Mi primer trabajo en OpenGL");//Abre ventana en pantalla
    glutDisplayFunc(miDibujo); //Registra la función de redibujar
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}

