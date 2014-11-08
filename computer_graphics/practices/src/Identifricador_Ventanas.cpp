#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>


// Parametros de la ventana 
#define An  600
#define Al 600
#define TITULO  "GLUT Demo: Uso de Subventanas"
int winIdMain;
int winIdSub;


// Variables del estado de la animación
#define SMALL_ANGLE  5.0
#define TIME_STEP    0.1
static double time = 0.0;
static double spin = 0.0;


// Dibuja un carácter en la posición actual
static char label[100];

void drawString (char *s)
{
  unsigned int i;
  for (i = 0; i < strlen (s); i++)
    glutBitmapCharacter (GLUT_BITMAP_HELVETICA_10, s[i]);
};

void drawStringBig (char *s)
{
  unsigned int i;
  for (i = 0; i < strlen (s); i++)
    glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, s[i]);
};


// Función actualizada en la llamada de la función main
void mi_Dibujo (void)
{
glutSetCursor (GLUT_CURSOR_CYCLE);
  // Limpia el dibujo de la pantalla 
  glutSetWindow (winIdMain);
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity ();

  // Escritura a pie de nota 
  glColor3f (1.0F, 1.0F, 1.0F);
  sprintf (label, "Ejemplo de Identficador de Ventanas: Presiona i para quitar y poner ventana");
  glRasterPos2f (-0.80F, -0.80F);
  drawString (label);


  // Dibuja el triángulo en rotación
  glPushMatrix ();
  glRotatef (spin, 0.0, 0.0, 1.0);
  glBegin (GL_POLYGON);
  glColor3f (1.0F, 0.0F, 0.0F);
  glVertex2f (0.0F, 0.5F);
  glColor3f (0.0F, 1.0F, 0.0F);
  glVertex2f (-0.4330F, -0.25F);
  glColor3f (0.0F, 0.0F, 1.0F);
  glVertex2f (0.433F, -0.25F);
  glEnd ();
  glPopMatrix ();

  glutSwapBuffers ();
};



//Otras funciones dibujadas, esta se utiliza 
//para actualizae el gráfico de la subventana
void subDisplay ()
{

  // Limpia la subventana
  glutSetWindow (winIdSub);
  glClearColor (0.25, 0.25, 0.25, 0.0);
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Dibuja el borde
  glColor3f (0.0F, 1.0F, 0.0F);
  glBegin (GL_LINE_LOOP);
  glVertex2f (0.0F, 0.0F);
  glVertex2f (0.0F, 0.99F);
  glVertex2f (0.999F, 0.99F);
  glVertex2f (0.999F, 0.0F);
  glEnd ();

  // Escribe el estado de la variable
  glColor3f (1.0F, 1.0F, 1.0F);
  sprintf (label, "Tiempo = %8.3f ", time);
  glRasterPos2f (0.05F, 0.75F);
  drawString (label);

  sprintf (label, "Angulo de Rotacion = %8.3f ", spin);
  glRasterPos2f (0.05F, 0.55F);
  drawString (label);

  sprintf (label, "Velocidad Rotacion  = %8.3f ", spin / time);
  glRasterPos2f (0.05F, 0.35F);
  drawString (label);

  // Escribe Banner e información
  glColor3f (1.0F, 0.0F, 1.0F);
  sprintf (label, " Esta es una subventana ");
  glRasterPos2f (0.40F, 0.70F);
  drawStringBig (label);

  sprintf (label, " Esta ventana tiene su propio contexto OpenGL ");
  glRasterPos2f (0.33F, 0.35F);
  drawStringBig (label);

  glutSwapBuffers ();
};


// Función de rellamada de main para el redimensionado
void mainReshape (int w, int h)
{
  glViewport (0, 0, w, h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluOrtho2D (-1.0F, 1.0F, -1.0F, 1.0F);
  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity ();

  glutSetWindow (winIdSub);
  glutReshapeWindow (w - 10, h / 10);
  glutPositionWindow (5, 5);
  glutSetWindow (winIdMain);

};


// Función de rellamada para el redimensionado de la subventana 
void subReshape (int w, int h)
{
  glViewport (0, 0, w, h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluOrtho2D (0.0F, 1.0F, 0.0F, 1.0F);
};


// Función del evento del teclado
void keyboard (unsigned char key, int x, int y)
{
  static int info_banner = 1;

  switch (key)
    {
    case 'i':
    case 'I':
      if (info_banner)
	{
	  glutSetWindow (winIdSub);
	  glutHideWindow ();
	}
      else
	{
	  glutSetWindow (winIdSub);
	  glutShowWindow ();
	};
      info_banner = !info_banner;
      break;
    case 'q':
    case 'Q':
      exit (0);
      break;
    };
};




// Sólo puede haber una llamada a la función de rellamada idle()
// En una animación, esta función idle() debe actualziarse no sólo
// en la función principal sino tambuién en todas las subventanas derivadas
void idle (void)
{

  // Actualiza el estado de la variables
  spin += SMALL_ANGLE;
  time += TIME_STEP;

  // Actualiza main y sub ventanas
  glutSetWindow (winIdMain);
  glutPostRedisplay ();
  glutSetWindow (winIdSub);
  glutPostRedisplay ();
};




int main (int argc, char **argv)
{

  /* Glut inicialización */
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowPosition (5, 5);
  glutInitWindowSize (An, Al);

  // Creación de la ventana Main e inicializa
  winIdMain = glutCreateWindow (TITULO);
  glutDisplayFunc (mi_Dibujo);
  glutReshapeFunc (mainReshape);
  glutKeyboardFunc (keyboard);
  glutIdleFunc (idle);

  // Creation de la Sub ventana e inicializa
  winIdSub = glutCreateSubWindow (winIdMain, 5, 5, An - 10, Al / 10);
  glutDisplayFunc (subDisplay);
  glutReshapeFunc (subReshape);

  glutMainLoop ();

  return 0;
};

