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

void mi_Inicio(void)
{
     glClearColor(1.0f,1.0f,1.0f,0.0f); //Selecciona el color de fondo
     glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, (double) An, 0.0, (double) Al);
     glPointSize(3.0);
}

void setWindow(float left,float right,float bottom,float top){
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(left,right,bottom,top);
     }

void setViewport(int left,int right,int bottom,int top){
     glViewport(left,bottom,right-left,top-bottom);
     }
     
void drawPolyLineFile(char* archivo){
     int i,j;
     fstream entrada;
     entrada.open(archivo,ios ::in); //abre el archivo    
     if(entrada.fail()) return;
    
     GLint numpolys, numLineas, x, y;
     entrada >> numpolys;
     for(j=0;j<numpolys;j++){
                             entrada >> numLineas;
                             glBegin(GL_LINE_STRIP);
                             glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
                             for(i=0;i<numLineas;i++){
                                                      entrada >>x >> y;
                                                      glVertex2i(x,y);
                                                      }
                                                      glEnd();
                             }
                             glFlush();
     entrada.close();
}

void miDibujo(void){
     glClear(GL_COLOR_BUFFER_BIT); //Limpia la pantalla
     //Dibuja las líneas de separación de las ventanas
     glColor3f(0.0f, 0.0f, 1.0f); //El color a dibujar
     setWindow(0.0,640.0,0.0,480.0);
     setViewport(0,640,0,480);
     glBegin(GL_LINES);
     glVertex2i(0,240);
     glVertex2i(640,240);
     glVertex2i(320,0);
     glVertex2i(320,480);
     glEnd();
     glFlush();
     glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
     //Esquina inferior izquierda
     setWindow(0.0,640.0,0.0,480.0);
     glViewport(0,0,320,240);
     drawPolyLineFile("dino.dat");
     //Esquina inferior derecha
     setWindow(0.0,320,0.0,240.0);
     glViewport(320,0,640,240);
     drawPolyLineFile("dino.dat");
     //Esquina superior izquierda
     setWindow(-10.0,240.0,320.0,600.0);
     glViewport(0,240,320,480);
     drawPolyLineFile("dino.dat");
     //Superior derecha
     setWindow(160.0,480.0,37.5,277.5);
     glViewport(320,240,640,480);
     drawPolyLineFile("dino.dat");
}

int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(100, 250); //Posiciona la ventana en la pantalla
    glutCreateWindow("Practica 3.1: Puerto de vista");//Abre ventana en pantalla
    glutDisplayFunc(miDibujo); //Registra la función de redibujar
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}
