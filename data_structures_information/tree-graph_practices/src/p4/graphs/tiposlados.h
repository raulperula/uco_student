#ifndef TIPOSLADOS_H
#define TIPOSLADOS_H

/**
 * @file    tiposlados.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include "creargrafo.h"

void tiposLados(GRAFO g);
void clasificacionLados(GRAFO g, int i, int *visitado, int *desc, int *prof, int *cont, char **tipoLado);

#endif
