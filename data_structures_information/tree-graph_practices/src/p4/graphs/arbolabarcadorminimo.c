/**
 * @file    arbolabarcadorminimo.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include "arbolabarcadorminimo.h"

void algoritmoPrim(GRAFO g)
{
 int i, j;
 double **arbolACM; /*matriz de conexion para el arbol */

 arbolACM = (double **) malloc(verNumeroNodos(g) *
 sizeof(double *));

 for(i = 0; i < verNumeroNodos(g); i++)
  arbolACM[i] = (double *)malloc(verNumeroNodos(g) *
  sizeof(double));

 Prim(g, arbolACM);
 printf("ARBOL ABARCADOR DE COSTE MINIMO\n");
 for(i = 0; i < verNumeroNodos(g);i++)
 {
  for(j = 0; j < verNumeroNodos(g); j++)
   printf(" %lf", arbolACM[i][j]);
  printf("\n");
 }

 for(i = 0; i < verNumeroNodos(g); i++)
  free(arbolACM[i]);

 free(arbolACM);
}

void Prim(GRAFO g, double **arbol)
{
 int i,j,k;
 int *cercano;
 double *coste;

 cercano = (int *) malloc( verNumeroNodos(g) * sizeof(int));
 coste = (double *) malloc( verNumeroNodos(g) * sizeof(double));

 for(i = 0; i < verNumeroNodos(g); i++)
  for(j = 0; j < verNumeroNodos(g); j++)
   arbol[i][j] = 1000000.0;

 for(i = 0; i < verNumeroNodos(g);i++)
 {
  cercano[i] = 0;
  coste[i] = verPeso(g, 0, i);
 }
/* Seleccion de los n-1 lados del arbol*/
 for(i = 1; i < verNumeroNodos(g); i++)
 {
 /* Seleccion del nodo de menor coste */
  k = 1;
  for(j = 2; j < verNumeroNodos(g); j++)
  {
   if (coste[j] < 10000000.0 && coste[j] < coste[k])
    {
     k = j;
    }
  }
  /* El nodo de menor coste pasa a formar parte del arbol */
  coste[k] = 10000000;
  arbol[k][cercano[k]] = verPeso(g, k,cercano[k]);
  arbol[cercano[k]][k] = verPeso(g, k,cercano[k]);

  /* Se corrige el vector cercano, considerando al nodo k */
  for(j = 1; j < verNumeroNodos(g); j++)
   {
    if (coste[j] < 10000000.0 && coste[j] > verPeso(g, j, k))
    {
     cercano[j] = k;
     coste[j] = verPeso(g, j, k);
    }
   }
 }
}

void algoritmoKruskal(GRAFO g)
{
 int i, j;
 double **arbolACM; /*matriz de conexion para el arbol */

 arbolACM = (double **) malloc(verNumeroNodos(g) *
 sizeof(double *));

 for(i = 0; i < verNumeroNodos(g); i++)
  arbolACM[i] = (double *)malloc(verNumeroNodos(g) *
  sizeof(double));

 Kruskal(g, arbolACM);
 printf("ARBOL ABARCADOR DE COSTE MINIMO (KRUSKAL)\n");
 for(i = 0; i < verNumeroNodos(g);i++)
 {
  for(j = 0; j < verNumeroNodos(g); j++)
   printf(" %lf", arbolACM[i][j]);
  printf("\n");
 }

 for(i = 0; i < verNumeroNodos(g); i++)
  free(arbolACM[i]);

 free(arbolACM);
}
 
void Kruskal(GRAFO g, double **arbol)
{
 int i,j,k;
 int *conjunto;
 struct lado *l;
 int numeroLados=0;
 struct lado aux;

 conjunto = (int *) malloc( verNumeroNodos(g) * sizeof(int));

 for(i = 0; i < verNumeroNodos(g); i++)
  for(j = 0; j < verNumeroNodos(g); j++)
   arbol[i][j] = 1000000.0;

 for(i = 0; i < verNumeroNodos(g); i++)
  {
   for(j = i+1; j < verNumeroNodos(g); j++)
    {
     if (verPeso(g, i, j) < 1000000.0)
      numeroLados++;
    }
   conjunto[i] = i;
  }
 /* reserva y creacion del vector de lados*/
 l = (struct lado *)malloc(numeroLados * sizeof(struct
  lado));

 k = 0;
 for(i = 0; i < verNumeroNodos(g); i++)
  {
   for(j = i+1; j < verNumeroNodos(g); j++)
    {
     if (verPeso(g, i, j) < 1000000.0)
      {
       l[k].peso = verPeso(g, i, j);
       l[k].origen = i;
       l[k].destino = j;
       k++;
      }
    }
  }
 /* ordenacion del vector de lados*/

 for(i = 0; i < numeroLados - 1; i++)
 {
  k = i;
  for(j = i+1; j < numeroLados; j++)
  {
   if (l[j].peso < l[k].peso)
    k = j;
  }
  aux = l[k];
  l[k] = l[i];
  l[i] = aux;
 }

 /* recorrido de los lados en orden creciente y formacion del
 arbol */
 k = 0; /* contador de lados evaluados*/
 i = 0; /*contador de lados seleccionados*/
 while (i < verNumeroNodos(g)-1)
 {
  if (conjunto[l[k].origen] != conjunto[l[k].destino])
   {
    arbol[l[k].origen][l[k].destino] = l[k].peso;
    arbol[l[k].destino][l[k].origen] = l[k].peso;
    fusionar(l[k], conjunto, verNumeroNodos(g));
    i++;
   }
  k++;
 }
}

void fusionar(struct lado l, int *conjunto,int n)
{
 int aux;
 int i;

 aux = conjunto[l.destino];
 for(i = 0;i < n;i++)
 {
  if (conjunto[i] == aux)
   conjunto[i] = conjunto[l.origen];
 }
}
