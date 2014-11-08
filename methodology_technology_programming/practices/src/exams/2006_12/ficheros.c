/**
 * @file    ficheros.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include"ficheros.h"


int numeroConejos(){
  FILE* f;
  int nconejos;
  f=fopen("conejos2006.bin","rb");
  fseek(f,0,SEEK_END);
  nconejos=ftell(f)/(sizeof(struct conejos));
  return nconejos;
}

