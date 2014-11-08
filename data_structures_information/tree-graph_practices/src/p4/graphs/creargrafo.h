#ifndef CREARGRAFO_H
#define CREARGRAFO_H

/**
 * @file    creargrafo.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <stdio.h>
#include <malloc.h>

struct grafo
{
 double **mConexion;
 int nNodos;
 char tipo; /*d = dirigido, n = no dirigido */
};
typedef struct grafo GRAFO;

void introducirGrafo(GRAFO *g);
void asignarTipoGrafo(GRAFO *g, char t);
char verTipoGrafo(GRAFO g);
void asignarNumeroNodos(GRAFO *g, int n);
int verNumeroNodos(GRAFO g);
void reservarGrafo(GRAFO *g);
void asignarPeso(GRAFO *g, int origen, int destino, double peso);
double verPeso(GRAFO g, int origen, int destino);
void asignarPesosGrafo(GRAFO *g);
void verPesosGrafo(GRAFO g);

#endif
