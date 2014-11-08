#ifdef WIN32
#include<windows.h>
#endif
#include<GL/gl.h>
#include<GL/glut.h>
#include<fstream>
#include <math.h>
#ifndef WIN32
#include <iostream>
#endif

#define An 400
#define Al 400
#define DOS_PI 6.283f


using namespace std;

class GLintPoint
{
public:
   GLint x,y;
};

class GLfloatPoint{
public:
   GLfloat x,y;
};

void mi_Inicio(void)
{
   glClearColor(1.0f,1.0f,1.0f,1.0f); //Selecciona el color de fondo
   glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
   glPointSize(3.0); //Tamaño de los puntos a dibujar
   glClear(GL_COLOR_BUFFER_BIT); //Limpia la pantalla
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, (double) An, 0.0, (double) Al);
}

void dibujaPuntos(GLintPoint T[3])
{
   int x;
   glBegin(GL_POINTS);
   glColor3f(0.0f, 1.0f, 0.0f); //El color a dibujar
   for(x=0;x<3;x++)
   {
      glBegin(GL_POINTS);
      glVertex2i(T[x].x,T[x].y);
      glEnd();
      glFlush();
   }
}

void dibujaCentro(GLfloatPoint S)
{
   glBegin(GL_POINTS);
   glVertex2i(S.x,S.y);
   glEnd();
   glFlush();
}

void dibujacirculo(GLfloatPoint S, float radio)
{
   GLfloat x,y,incre, theta=0;
   int n = 100;//Polígono regular de 100 lados
   incre = DOS_PI/(float)n;
   glColor3f(1.0f, 0.0f, 0.0f); //El color a dibujar
   for (int i =0; i<= n; i++)
   {
      theta += incre;
      x = S.x + radio*cos(theta);
	  y= S.y + radio*sin(theta);
	  glBegin(GL_LINE_STRIP);
	  glVertex2f(x,y);
	}
	glEnd();
	glFlush();
}

void MiDibujo(void)
{
   glClear(GL_COLOR_BUFFER_BIT); //Limpia la pantalla
   glBegin(GL_POINTS);// para pintar la función
   glColor3f(1.0f, 1.0f, 0.0f); //El color a dibujar
   glEnd();
   glFlush();
}

void circulo(GLintPoint T[3])
{
   static GLfloatPoint a,b,c,an,S;
   static float radio;

   //Calculo de a,b,c
   a.x=(float)T[1].x-(float)T[0].x;
   a.y=(float)T[1].y-(float)T[0].y;
   b.x=(float)T[2].x-(float)T[1].x;
   b.y=(float)T[2].y-(float)T[1].y;
   c.x=(float)T[0].x-(float)T[2].x;
   c.y=(float)T[0].y-(float)T[2].y;

   //vector normal an
   an.x=-a.y;
   an.y=a.x;

   //Calculo de intermedios
   S.x=T[0].x+0.5*(a.x+(b.x*c.x+b.y*c.y)/(an.x*c.x+an.y*c.y)*an.x);
   S.y=T[0].y+0.5*(a.y+(b.x*c.x+b.y*c.y)/(an.x*c.x+an.y*c.y)*an.y);
   radio=0.5*sqrt(a.x*a.x+a.y*a.y)*sqrt((b.x*c.x+b.y*c.y)/(an.x*c.x+an.y*c.y)*(b.x*c.x+b.y*c.y)/(an.x*c.x+an.y*c.y)+1);

   glClear(GL_COLOR_BUFFER_BIT); //Limpia la pantalla
   dibujaPuntos(T);
   dibujaCentro(S);
   dibujacirculo(S,radio);
}

void myMouse(int boton, int estado, int x, int y)
{

   static GLintPoint corners[3];
   static int numCorners = 0;
   if (boton ==GLUT_LEFT_BUTTON && estado == GLUT_DOWN)
   {
      corners[numCorners].x =x;
      corners[numCorners].y = Al - y;
      if(++numCorners ==3)
	  {
         circulo(corners); //le pasamos los puntos a la funcion circulo
         numCorners = 0; //vuelve a 0 la esquina
	  }
   }
   else if(boton == GLUT_RIGHT_BUTTON && estado == GLUT_DOWN)
      glClear(GL_COLOR_BUFFER_BIT); //limpia la ventana
      glFlush();
}

int main (int argc,char** argv)
{
   glutInit(&argc, argv); //Inicializa toolkit
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Selec. el modo pantalla
   glutInitWindowSize(An,Al); //Selecciona el tamaño de la ventana
   glutInitWindowPosition(100, 150); //Posiciona la ventana en la pantalla
   glutCreateWindow("Practica 2.7: Circulo introduciendo puntos por raton");//Abre ventana en pantalla
   glutMouseFunc(myMouse);
   glutDisplayFunc(MiDibujo); //Registra la función de redibujar
   mi_Inicio();
   glutMainLoop(); //Bucle continuo
   return 0;
}

