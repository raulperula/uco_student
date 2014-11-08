/**
 * @file    recorridos.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include "recorridos.h"

void profundidad(GRAFO g)
{
 int *visitado;
 int i;

 visitado = (int *) malloc(verNumeroNodos(g) *
 sizeof(int));
 for(i = 0; i < verNumeroNodos(g);i++)
 {
  visitado[i] = 0;
 }
 for(i = 0; i < verNumeroNodos(g);i++)
 {
  if (visitado[i] == 0)
  {
   recorridoProfundidad(g, i, visitado);
  }
 }
 free(visitado);
}

void recorridoProfundidad(GRAFO g, int i, int *visitado)
{
 int j;

 visitado[i] = 1;
 printf(" %d", i);

 for(j = 0; j < verNumeroNodos(g); j++)
 {
  if (verPeso(g, i, j) < 1000000.0 && visitado[j] == 0)
   recorridoProfundidad(g, j, visitado);
 }
}

void amplitud(GRAFO g)
{
 int *visitado;
 int i;    
 struct cola *colaNodos = NULL;

 visitado = (int *) malloc(verNumeroNodos(g) *
 sizeof(int));
 for(i = 0; i < verNumeroNodos(g);i++)
 {
  visitado[i] = 0;
 }
 for(i = 0; i < verNumeroNodos(g);i++)
 {
  if (visitado[i] == 0)
  {
   recorridoAmplitud(g, i, visitado, &colaNodos);
  }
 }
 free(visitado);
}

void recorridoAmplitud(GRAFO g, int i, int *visitado, struct cola **colaNodos)
{
 int j;
 int x;

 visitado[i] = 1;
 printf(" %d", i);
 insertarCola(colaNodos, i);

 while(colaVacia(*colaNodos) == 0)
 {
  x = extraerCola(colaNodos);
  for(j = 0; j < verNumeroNodos(g); j++)
  {
   if (verPeso(g, x, j) < 1000000.0 && visitado[j] == 0)
   {
    visitado[j] = 1;
    insertarCola(colaNodos, j);
    printf(" %d", j);
   }
  }
 }
}

void topologica(GRAFO g)
{
 int i;
 int *visitado;
    
 visitado = (int *) malloc(verNumeroNodos(g) *
 sizeof(int));
 for(i = 0; i < verNumeroNodos(g);i++)
 {
  visitado[i] = 0;
 }
 for(i = 0; i < verNumeroNodos(g);i++)
 {
  if (visitado[i] == 0)
  {
   clasificacionTopologica(g, i, visitado);
  }
 }
 free(visitado);
}

void clasificacionTopologica(GRAFO g, int i, int *visitado)
{
 int j;

 visitado[i] = 1;

 for(j = 0; j < verNumeroNodos(g); j++)
 {
  if (verPeso(g, i, j) < 1000000.0 && visitado[j] == 0)
   clasificacionTopologica(g, j, visitado);
 }
 printf(" %d", i);
}
