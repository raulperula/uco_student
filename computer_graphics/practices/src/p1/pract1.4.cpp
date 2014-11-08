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
#define An 400
#define Al 400
#define GL_PI 3.14159265f

using namespace std;
class GLintPoint{
      public:
             GLint x,y;
};
             
void mi_Inicio(void)
{
     glClearColor(1.0f,1.0f,1.0f,0.0f); //Selecciona el color de fondo
     glColor3f(1.0f, 1.0f, 1.0f); //El color a dibujar
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, (double) An, 0.0, (double) Al);
     glPointSize(3.0);
}


int random(int m){
    return rand( )%m;
}

void drawDot(int x, int y){
     glBegin(GL_POINTS);
     glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar

     glVertex2i(x,y);
     glEnd();
     glFlush();
}

void Sierpinski(void){
     glClear(GL_COLOR_BUFFER_BIT); //Limpia la pantalla
     GLintPoint T[3]={ {50,60}, {340,80}, {240,350} }; // Coordenadas vértices
     int index = random(3); //devuelve 0, 1, o 2
     GLintPoint point =T[index]; //inicializa los puntos
     drawDot(point.x, point.y); //dibuja punto inicial
     for(int i =0; i< 10000; i++) //dibuja 1000 puntos
     {
             index = random(3);
             point.x = (point.x + T[index].x) /2;
             point.y = (point.y + T[index].y) /2;
             drawDot(point.x, point.y);
     }
     glFlush();
}


int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(100, 250); //Posiciona la ventana en la pantalla
    glutCreateWindow("Mi primer trabajo en OpenGL");//Abre ventana en pantalla
    glutDisplayFunc(Sierpinski); //Registra la función de redibujar
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}

