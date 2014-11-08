/**
 * @file    principal.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include "principal.h"

int main(void)
{
 GRAFO g;
 int opcion;
 do
 {
  opcion = menu();
  switch (opcion)
  {
   case 1:
    introducirGrafo(&g);
    break;
   case 2: /*Algoritmo de Dijkstra */
    algoritmoDijkstra(g);

    getchar();
    getchar();
    getchar();
    break;

   case 3: /*Algoritmo de Floyd */
    algoritmoFloyd(g);

    getchar();
    getchar();
    getchar();
    break;

   case 4: /*Algoritmo de Prim */
    if (verTipoGrafo(g) == 'n')
     algoritmoPrim(g);
    else
     printf("El grafo es dirigido\n");

    getchar();
    getchar();
    getchar();
    break;

   case 5: /*Algoritmo de Kruskal */
    if (verTipoGrafo(g) == 'n')
     algoritmoKruskal(g);
    else
     printf("El grafo es dirigido\n");
     
    getchar();
    getchar();
    getchar();
    break;

  case 6: /* busqueda en profundidad */
    profundidad(g);
    getchar();
    getchar();
    break;

   case 7: /* busqueda en amplitud */
    amplitud(g);
    getchar();
    getchar();
    break;

  case 8: /* Clasificación Topológica */
   if (verTipoGrafo(g) == 'd')
    topologica(g);
   else
    printf("El grafo es no dirigido\n");
    
    getchar();
    getchar();
    break;

   case 9: /* Clasificación de los lados de grafo dirigido en base a la búsqueda en profundidad */
   if (verTipoGrafo(g) == 'd')
    tiposLados(g);
   else
    printf("El grafo es no dirigido\n");
    
    getchar();
    getchar();
    break;

  }
 }while (opcion != 0);
}
