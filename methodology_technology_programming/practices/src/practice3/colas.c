/**
 * @file    colas.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include<colas.h>

void insertarCola(colas** cola){
  colas aux;
  aux->sig=*cola;
  *cola=aux;
}
