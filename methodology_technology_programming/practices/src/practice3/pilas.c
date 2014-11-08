/**
 * @file    pilas.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include<pilas.h>


void insertarPila(pilas** pila){
  pilas* aux;
  aux->sig=*pila;
  *pila=aux;
}

int extraerPila(pilas** pila){
  pilas* marca;
  int aux;
  aux=*pila.n;
  marca=*pila;
  *pila==*pila->sig;
  free(marca);
  return aux;
}

