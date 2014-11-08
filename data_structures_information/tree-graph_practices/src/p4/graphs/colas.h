#ifndef COLAS_H
#define COLAS_H

/**
 * @file    colas.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct cola
{
 int n;
 struct cola *sig;
};

struct cola *nuevoElemento();

void insertarCola(struct cola **cabeza, int n);
int extraerCola(struct cola **cabeza);
int colaVacia(struct cola *cabeza);

#endif
