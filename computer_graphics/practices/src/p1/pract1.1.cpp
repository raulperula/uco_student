#ifdef WIN32
#include<windows.h>
#endif
#include<GL/gl.h>
#include<GL/glut.h>
#include<fstream>
#ifndef WIN32
#include <iostream>
#endif
#define An 640
#define Al 480

using namespace std;

void mi_Inicio(void)
{
     glClearColor(0.6f,0.4f,0.12f,0.0f); //Selecciona el color de fondo
     glColor3f(1.0f, 1.0f, 1.0f); //El color a dibujar
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, (double) An, 0.0, (double) Al);
}

void dibuja_puntos(char *archivo)
{
     fstream Entrada;
     Entrada.open(archivo, ios ::in); //abre el fichero
     if(Entrada.fail() ) return;
     glClear(GL_COLOR_BUFFER_BIT); //limpia la pantalla
     GLint num_puntos, x, y;
     GLfloat tama_pixel;
     Entrada >> tama_pixel;
     glPointSize(tama_pixel); //lee el tamaño de los puntos
     Entrada >> num_puntos; //le el número de puntos
     for(int j =0; j < num_puntos; j++) //lee cada polilínea
     {
     glBegin(GL_POINTS); //dibuja la siguiente polilínea
     Entrada >> x >> y; //lee el siguiente par de x, y
     glVertex2i(x ,y);
     glEnd();
     }
     glFlush();
     Entrada.close();
}

void miDibujo(void)
{
     char *archivo;
     archivo = "puntos.dat";
     dibuja_puntos(archivo);
}


int main(int argc, char **argv){
    glutInit(&argc, argv); //Inicializa toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
    glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
    glutInitWindowPosition(100, 150); //Posiciona la ventana en la pantalla
    glutCreateWindow("Mi primer trabajo en OpenGL");//Abre ventana en pantalla
    glutDisplayFunc(miDibujo); //Registra la función de redibujar
    mi_Inicio();
    glutMainLoop(); //Bucle continuo
    return 0;
}

