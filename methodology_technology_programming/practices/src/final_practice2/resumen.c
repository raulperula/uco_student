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
#include"imagen.h"


int main(){

  char fichero1[25];
  char fichero2[25];
  char fichero3[25];
  char fichero4[25];
  imagen aux;
  int opcion;
  printf("1.-Descodificar Mensaje\n");
  printf("2.-Codificar Mensaje");
  scanf("%d",&opcion);
  switch(opcion){
    case 1:
      printf("dame el nombre del fichero origen:");
      scanf("%s",fichero1);
      aux=leerImagen(fichero1);
      leerMensaje(fichero1,aux);
      break;
    case 2:    
      printf("\ndame el nombre del fichero imagen origen:");
      scanf("%c",fichero2);
      printf("\nDame el nombre del fichero imagen destino:");
      scanf("%c",fichero3);
      printf("Dame el nombre del fichero de textoorigen:");
      scanf("%c",fichero4);
    
    
  }
  return 0;
}
