/**
 * @file    caminsominimos.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include "caminosminimos.h"

void algoritmoDijkstra(GRAFO g)
{
 double *distancias;
 int *predecesores;
 int origen, i;
 
 predecesores = (int *) malloc (verNumeroNodos(g) *
 sizeof(int));
 distancias = (double *) malloc (verNumeroNodos(g) *
 sizeof(double));
 printf("Nodo origen: ");
 scanf("%d",&origen);
 Dijkstra(g, distancias, predecesores, origen);
 for(i = 0; i < verNumeroNodos(g);i++)
 {
  printf(" La distancia minima al nodo %d es %lf\n", i,
  distancias[i]);
  printf("El camino minimo al nodo %d es:\n", i);
  caminoDijkstra(origen, i, predecesores);
 }

    free(distancias);
    free(predecesores);
}

void Dijkstra(GRAFO g, double *d, int *p, int origen)
{
 int i,j;
 int *s;
 double minimo;
 int x;

 s = (int *) malloc (verNumeroNodos(g) *
    sizeof(int));

 for(i = 0; i < verNumeroNodos(g); i++)
 {
  p[i] = origen;
  d[i] = verPeso(g, origen, i);
  s[i] = 0;
  }

 s[origen] = 1;

 for(i = 0; i < verNumeroNodos(g) - 1; i++)
 {
  /* Buscar Nodo de distancia minima */
  minimo = 1000000.0;
  for(j = 0; j < verNumeroNodos(g); j++)
  {
   if (d[j] <= minimo && s[j] == 0)
   {
    minimo = d[j];
    x = j;
   }
  }
   s[x] = 1; /* El nodo x pasa al conjunto s */
  /* Comprobamos si el nodo x acorta las distancias */
  for(j = 0; j < verNumeroNodos(g); j++)
  {
   if (s[j] == 0 && d[j] > d[x] + verPeso(g, x, j))
   {
    d[j] = d[x] + verPeso(g, x, j);
    p[j] = x;
   }
  }
 }
 free(s);
}

void caminoDijkstra(int origen, int destino, int *p)
{
 int k;

 printf("%d <- ", destino);
 k = p[destino];

 while(k != origen)
 {
  printf("%d <- ",k);
  k = p[k];
 }

 printf("%d\n",origen);
}

void algoritmoFloyd(GRAFO g)
{
 double **distanciasFloyd;
 int **intermedios;
 int i,j;

 distanciasFloyd = (double **) malloc(verNumeroNodos(g) *
 sizeof(double *));

 for(i = 0; i < verNumeroNodos(g); i++)
  distanciasFloyd[i] = (double *)malloc(verNumeroNodos(g) *
  sizeof(double));

  intermedios = (int **) malloc(verNumeroNodos(g) *
  sizeof(int *));

  for(i = 0; i < verNumeroNodos(g); i++)
  intermedios[i] = (int *)malloc(verNumeroNodos(g) *
  sizeof(int));

  Floyd(g, distanciasFloyd, intermedios);
  for(i = 0; i < verNumeroNodos(g);i++)
   for(j = i+1; j < verNumeroNodos(g); j++)
   {
    printf(" \nLa distancia minima entre %d y %d es %lf\n", i, j,
    distanciasFloyd[i][j]);
    printf("El camino minimo entre %d y %d es:", i, j);
    caminoFloyd(intermedios,i,j);
   }
  for(i = 0; i < verNumeroNodos(g); i++)
  {
   free(distanciasFloyd[i]);
   free(intermedios[i]);
  }

  free(distanciasFloyd);
  free(intermedios);
}

void Floyd(GRAFO g,double **distancias, int
**intermedios)
{
 int i, j, k;

 for(i = 0;i < verNumeroNodos(g); i++)
  for(j = 0;j < verNumeroNodos(g); j++)
  {
   distancias[i][j] = verPeso(g, i, j);
   intermedios[i][j] = -1;
  }
 for(k = 0;k < verNumeroNodos(g); k++)
  for(i = 0;i < verNumeroNodos(g); i++)
   for(j = 0;j < verNumeroNodos(g); j++)
   {
    if (distancias[i][j] > distancias[i][k] + distancias[k][j])
    {
     distancias[i][j] = distancias[i][k] + distancias[k][j];
     intermedios[i][j] = k;
    }
   }
}

void caminoFloyd(int **intermedios, int origen, int destino)
{
 int k;

 k = intermedios[origen][destino];

 if (k != -1)
 {
  caminoFloyd(intermedios, origen, k);
  printf(" %d", k);
  caminoFloyd(intermedios, k, destino);
 }
}
