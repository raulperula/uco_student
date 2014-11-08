/**
 * @file    menu.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include "menu.h"

int menu()
{
	int opcion;
	
	system("clear");
	
	printf("  0. Salir................................\n");
	printf("  1. Introducir Grafo.....................\n");
	printf("  2. Algoritmo de Dijkstra(GD y GND)......\n");
	printf("  3. Algoritmo Floyd(GD y GND)............\n");
	printf("  4. Algoritmo Prim(GND)..................\n");
	printf("  5. Algoritmo Kruskal(GND)...............\n");
	printf("  6. Recorrido en profundidad(GD y GND)...\n");
	printf("  7. Recorrido en amplitud(GD y GND)......\n");
	printf("  8. Clasif. Topologica(GD aciclicos).....\n");
	printf("  9. Tipos de lados (b.en prof.para GD)...\n");
	
	printf("Introduzca opcion...: ");
	scanf("%d", &opcion);

	return opcion;
}
