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
#define An 600
#define Al 500
#define GL_PI 3.14159265f

using namespace std;

void mi_Inicio(void)
{
     glClearColor(1.0f,1.0f,1.0f,0.0f); //Selecciona el color de fondo
     glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, (double) An, 0.0, (double) Al);
     glPointSize(3.0);
}

void miDibujo(void){
     GLint xInicial = 25, yInicial = 150; //posición inicial
     GLubyte etiqueta[36] = {'E','n','e','F','e','b', 'M','a','r','A','b','r','M','a','y','J','u','n','J','u','l','A','g','o','S','e','p','O','c','t', 'N','o','v','D','i','c'};
     GLint ValorDatos [12] = {420, 342, 324, 310, 262, 185, 190, 196, 217, 240, 312, 438};
     int k,i;
     int mes;
     glClear(GL_COLOR_BUFFER_BIT);
     // Dibuja Caracteres
     glColor3f(1.0,0.0,0.0); //Color a dibujar Rojo
     for(k=0; k< 12; k++){
              glRasterPos2i (xInicial + k*50, ValorDatos [k] - 4);
              glutBitmapCharacter (GLUT_BITMAP_9_BY_15, '*');
              }
     //Eje
     glBegin(GL_LINES);
     glColor3f(0.0,1.0,0.0);
     glVertex2i(10,170);
     glVertex2i(10,Al-50);
     glVertex2i(10,170);
     glVertex2i(An-10,170);
     glEnd();
     
     //dibuja lineas
     glBegin(GL_LINE_STRIP);
     glColor3f(0.0,0.0,1.0);
     for(i=0;i<12;i++){
                       glVertex2i(xInicial+i*50,ValorDatos[i]);
                       }
     glEnd();
     
     //Dibuja el texto
     glColor3f(0.0,0.0,0.0); //Color a dibujar Negro
     xInicial =20;
     for(mes =0; mes < 12; mes++){
             glRasterPos2i (xInicial,yInicial);
             for (k=3*mes; k<3*mes + 3; k++) glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12, etiqueta [k]);
             xInicial += 50;
             }
     glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(250, 150); //Posiciona la ventana en la pantalla
    glutCreateWindow("Practica 1.10:Grafico");//Abre ventana en pantalla
    glutDisplayFunc(miDibujo); //Registra la función de redibujar
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
} 
