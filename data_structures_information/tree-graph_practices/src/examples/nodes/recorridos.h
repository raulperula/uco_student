#ifndef RECORRIDOS_H
#define RECORRIDOS_H

/**
 * @file    recorridos.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include "creargrafo.h"
#include "colas.h"

void profundidad(GRAFO g);
void amplitud(GRAFO g);
void topologica(GRAFO g);
void recorridoProfundidad(GRAFO g, int i, int *visitado);
void recorridoAmplitud(GRAFO g, int i, int *visitado, struct cola **colaNodos);
void clasificacionTopologica(GRAFO g, int i, int *visitado);

#endif
