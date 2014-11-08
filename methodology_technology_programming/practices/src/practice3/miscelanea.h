/**
 * @file    miscelanea.h
 * @brief   Header file.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */
 
#include<math.h>

struct lista{
  int nlados;
  int* puntos;
  int sig;
};

void imprimirListaTriangulos(struct lista* listaTriangulos);
int calcularPerimetro(struct lista* listaTriangulos);
