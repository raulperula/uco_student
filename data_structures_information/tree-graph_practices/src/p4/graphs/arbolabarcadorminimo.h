#ifndef ARBOLABARCADORMINIMO_H
#define ARBOLABARCADORMINIMO_H

/**
 * @file    arbolabarcadorminimo.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include "creargrafo.h"

struct lado
{
 double peso;
 int origen;
 int destino;
};

void algoritmoPrim(GRAFO g);
void algoritmoKruskal(GRAFO g);
void Prim(GRAFO g, double **arbol);
void Kruskal(GRAFO g, double **arbol);
void fusionar(struct lado l, int *conjunto,int n);

#endif
