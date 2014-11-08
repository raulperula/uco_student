#ifndef CAMINOSMINIMOS_H
#define CAMINOSMINIMOS_H

/**
 * @file    caminosminimos.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include "creargrafo.h"

void algoritmoDijkstra(GRAFO g);
void Dijkstra(GRAFO g, double *d, int *p, int origen);
void caminoDijkstra(int origen, int destino, int *p);
int menu();
void Floyd(GRAFO g,double **distancias, int
**intermedios);
void caminoFloyd(int **intermedios, int origen, int destino);

#endif

