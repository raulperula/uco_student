/**
 * @file    creargrafo.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include "creargrafo.h"

void introducirGrafo(GRAFO *g)
{
 int n;
 char tipo;
 int i,j;
 getchar();
 do
 {
  printf("Tipo de grafo (d = dirigido, n = no dirigido): ");
  scanf("%c", &tipo);
 } while (tipo != 'd' && tipo != 'n');
 asignarTipoGrafo(g, tipo);
 
 printf("Numero de nodos del grafo: ");
 scanf("%d", &n);
 asignarNumeroNodos(g, n);
 reservarGrafo(g);
 asignarPesosGrafo(g);
 /* Los siguientes son ejemplos de introducción para probar los
 algoritmos, asignando los pesos de los lados linea a linea*/
 
 /*for(i = 0; i < verNumeroNodos(*g); i++)
  for(j = 0; j < verNumeroNodos(*g); j++)
   asignarPeso(g, i, j, 1000000.0);*/

 /* Grafo de prueba (no dirigido) para busqueda en profundidad y busqueda en amplitud */
 /*asignarPeso(g,0,1, 1.0);
    asignarPeso(g,1,0, 1.0);
    asignarPeso(g,0,2, 1.0);
    asignarPeso(g,2,0, 1.0);
    asignarPeso(g,0,3, 1.0);
    asignarPeso(g,3,0, 1.0);
    asignarPeso(g,0,4, 1.0);
    asignarPeso(g,4,0, 1.0);
    asignarPeso(g,1,3, 1.0);
    asignarPeso(g,3,1, 1.0);
    asignarPeso(g,1,4, 1.0);
    asignarPeso(g,4,1, 1.0);
    asignarPeso(g,2,5, 1.0);
    asignarPeso(g,5,2, 1.0);
    asignarPeso(g,2,6, 1.0);
    asignarPeso(g,6,2, 1.0);
    asignarPeso(g,3,4, 1.0);
    asignarPeso(g,4,3, 1.0);
    asignarPeso(g,5,6, 1.0);
    asignarPeso(g,6,5, 1.0);*/

  /* Grafo dirigido aciclico para probar la clasificación topológica */
  /*asignarPeso(g,0,2, 1.0);
    asignarPeso(g,1,2, 1.0);
    asignarPeso(g,1,3, 1.0);
    asignarPeso(g,2,4, 1.0);
    asignarPeso(g,3,4, 1.0);*/

 /* Grafo dirigido para probar la clasificacion de los lados del grafo en base al recorrido en prof. */
 /*asignarPeso(g,0,1, 1.0);
    asignarPeso(g,1,2, 1.0);
    asignarPeso(g,1,3, 1.0);
    asignarPeso(g,2,0, 1.0);
    asignarPeso(g,0,3, 1.0);
    asignarPeso(g,3,2, 1.0);
    asignarPeso(g,4,3, 1.0);
    asignarPeso(g,4,5, 1.0);
    asignarPeso(g,4,6, 1.0);
    asignarPeso(g,5,3, 1.0);*/
}

void asignarTipoGrafo(GRAFO *g, char t)
{
 g->tipo = t;
}

char verTipoGrafo(GRAFO g)
{
 return g.tipo;
}

void asignarNumeroNodos(GRAFO *g, int n)
{
 g->nNodos = n;
}

int verNumeroNodos(GRAFO g)
{
 return g.nNodos;
}

void reservarGrafo(GRAFO *g)
{
 int i;

 g->mConexion = (double **) malloc(verNumeroNodos(*g) *
 sizeof(double *));

 for(i = 0; i < verNumeroNodos(*g); i++)
  (g->mConexion)[i] = (double *)malloc(verNumeroNodos(*g) *
 sizeof(double));
}

void asignarPeso(GRAFO *g, int origen, int destino, double peso)
{
 (g->mConexion)[origen][destino] = peso;
}

double verPeso(GRAFO g, int origen, int destino)
{
 return (g.mConexion)[origen][destino];
}

void asignarPesosGrafo(GRAFO *g)
{
 int i,j;
 double aux;
 
 if (verTipoGrafo(*g) == 'n') /* Grafo ND */
 {
  for(i = 0; i < verNumeroNodos(*g); i++)
  {
   for(j = i+1; j < verNumeroNodos(*g); j++)
   {
    printf("Elemento %d %d =",i,j);
    scanf("%lf", &aux);
    asignarPeso(g, i, j, aux);
    asignarPeso(g, j, i, aux);
   }
   asignarPeso(g, i, i, 1000000.0);
  }
 }
 
 else /* Grafo D*/
 {
  for(i = 0; i < verNumeroNodos(*g); i++)
  {
   for(j = 0; j < verNumeroNodos(*g); j++)
   {
    printf("Elemento %d %d =",i,j);
    scanf("%lf", &aux);
    asignarPeso(g, i, j, aux);
   }
  }
 }
}

void verPesosGrafo(GRAFO g)
{
 int i,j;

 for(i = 0; i < verNumeroNodos(g); i++)
  {
   for(j = 0; j < verNumeroNodos(g); j++)
   {
    printf("%lf ", verPeso(g, i, j));
   }
   printf("\n");
  }
}
