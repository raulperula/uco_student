/**
 * @file    imagen.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */
 
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct imag{
  char numeromag[3];
  int col;
  int fil;
  int n_max;
  unsigned char ** matriz;
};

typedef struct imag imagen;

void escribirImagen(char* n2,imagen aux);
imagen leerImagen(char* n);
void leerMensaje(char* nomb,imagen im);
unsigned char binToDec(unsigned char* lsb,int ini);
