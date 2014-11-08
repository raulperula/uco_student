/**
 * @file    principal.c
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


int main(){
  int nreg;
  struct lista* registros;
  
  nreg=calcularReg();
  almacenaRegistros(registros,nreg);
  visualizarReg(registros,nreg);







  return 0;

}
