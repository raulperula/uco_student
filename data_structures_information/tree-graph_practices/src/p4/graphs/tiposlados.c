/**
 * @file    tiposlados.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include "tiposlados.h"

void tiposLados(GRAFO g)
{
 int *visitado;
 char **tipoLado;
 int *numeroProfundidad;
 int *numeroDescendientes;
 int contadorProfundidad = 0;
 int i,j;

 visitado = (int *) malloc(verNumeroNodos(g) * sizeof(int));
 numeroDescendientes = (int *) malloc(verNumeroNodos(g) * sizeof(int));
 numeroProfundidad = (int *) malloc(verNumeroNodos(g) * sizeof(int));
 tipoLado = (char **)malloc(verNumeroNodos(g) * sizeof(char *));

 for(i = 0; i < verNumeroNodos(g);i++)
  tipoLado[i] = (char *) malloc(verNumeroNodos(g) * sizeof(char));

 for(i = 0; i < verNumeroNodos(g);i++)
 {
  visitado[i] = 0;
  numeroDescendientes[i] = 0;
  numeroProfundidad[i] = 0;
 }

 for(i = 0; i < verNumeroNodos(g); i++)
  for(j = 0; j < verNumeroNodos(g); j++)
   tipoLado[i][j] = '*';

 for(i = 0; i < verNumeroNodos(g);i++)
 {
  if (visitado[i] == 0)
  {
   clasificacionLados(g, i, visitado,
   numeroDescendientes, numeroProfundidad,
	&contadorProfundidad, tipoLado);
  }
 }

 /* Clasificacion de lados que no son de árbol  (a = avance, r =
 retroceso, c = cruzado */
 for(i = 0; i < verNumeroNodos(g); i++)
 {
  for(j = 0; j < verNumeroNodos(g); j++)
  {
   if (tipoLado[i][j] != 'A' && verPeso(g, i, j) < 1000000.0)
   {
    if (numeroProfundidad[i] < numeroProfundidad[j])
     tipoLado[i][j] = 'a';
    else if ((numeroProfundidad[i] > numeroProfundidad[j])
    && (numeroProfundidad[i] < numeroProfundidad[j] +
    numeroDescendientes[j]))
     tipoLado[i][j] = 'r';
    else
     tipoLado[i][j] = 'c';
   }
  }
 }

    /* Visualizacion de los tipos de lados */
 for(i = 0; i < verNumeroNodos(g); i++)
 {
  for(j = 0; j < verNumeroNodos(g); j++)
  {
   printf(" %c", tipoLado[i][j]);
  }
  printf("\n");
 }

 free(visitado);
 free(numeroDescendientes);
 free(numeroProfundidad);

 for(i = 0; i < verNumeroNodos(g);i++)
  free(tipoLado[i]);

 free(tipoLado);
}

void clasificacionLados(GRAFO g, int i, int *visitado, int *desc, int *prof, int *cont, char **tipoLado)
{
 int j;
 
 (*cont)++;
 visitado[i] = 1;
 prof[i] = *cont;

 for(j = 0; j < verNumeroNodos(g); j++)
 {
  if (verPeso(g, i, j) < 1000000.0 && visitado[j] == 0)
  {
   tipoLado[i][j] = 'A';
   clasificacionLados(g, j, visitado, desc, prof, cont,
   tipoLado);
   desc[i] += desc[j] + 1;
  }
 }
}
