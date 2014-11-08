#ifndef _ESTEGANOGRAFIA_H_
#define _ESTEGANOGRAFIA_H_

/**
 * @file    esteganografia.h
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
#include <math.h>

void obtenerLSB(int **, int **, int, int);

void obtenerMensaje(int *, int **, int, int, int);

void leerMensaje(char *, char *);

#endif

