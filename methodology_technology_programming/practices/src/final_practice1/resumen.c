/**
 * @file    resumen.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include<stdio.h>
#include"fichero.h"
#include"listas.h"
#include"miscelanea.h"

int main(int argc,char** argv){
  struct lista* listaGeneral;
  struct lista* listaTriangulos;
  construirListas(char* argv[1],struct lista ** listaTriangulos, struct lista ** listaGeneral);
  imprimirListaTriangulos(struct lista* listaTruangulos);
  borrarElemento(struct lista** listaTriangulos);
}
