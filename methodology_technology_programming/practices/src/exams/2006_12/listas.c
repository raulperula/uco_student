/**
 * @file    listas.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include"listas.h"

struct conejo{
  char codigo[6];
  int edad;
  double peso;
};

struct lista{
  char codigo[6];
  int edad;
  double peso;
  struct lista* sig;
};

struct lista* nuevoElem(){
  return (((struct lista *)malloc(sizeof(struct lista)));
}

