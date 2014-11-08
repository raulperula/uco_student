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
#define An 640
#define Al 480
#define GL_PI 3.14159265f

using namespace std;

int random(int m){
    return rand( )%m;
}
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

void dibujo_aleatorio(int num, float numColor, int Ancho, int Alto)
{
glClearColor(numColor,numColor,numColor,0.0);
glClear(GL_COLOR_BUFFER_BIT);
for (int i=0; i<num ;i++)
{
GLint x1 = random(An);//situa la esquina aleatoriamente
GLint y1 = random(Al);
GLint x2 = random(An);//ajusta el ancho
GLint y2 = random(Al);
GLfloat lev = random(10)/10.0; // valor aleatorio entre 0 y 1
glColor3f(lev,lev,lev); //Especifica el un nivel de gris
glRecti(x1,y1,x2,y2); //Dibuja el rectángulo
}
glFlush();
}

void midibujo(void){
     dibujo_aleatorio(8,1.0,200,380);
}



int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(100, 250); //Posiciona la ventana en la pantalla
    glutCreateWindow("Practica 1.6:Rectangulos de tamaño y color aleatorios");//Abre ventana en pantalla
    glutDisplayFunc(midibujo); //Registra la función de redibujar
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}
    
