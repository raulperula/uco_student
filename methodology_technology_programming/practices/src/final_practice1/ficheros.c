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
#include"listas.h"
#include<stdio.h>

void construirListas(char* nombFichero,struct lista ** listaTriangulos, struct lista ** listaGeneral){
  struct lista* poligono;
  int nlados;
  int i;
  FILE* f;
  f=fopen(nombFichero,"rt");
  while((fscanf(f,"%d",&nlados))==1){
    nuevoelem(struct lista* poligono;int nlados);
    for(i=0;i<nlados*2;i++){
      fscanf(f,"%d",&(poligono->puntos[i]));
      if(nlados==3){ insertaLista(struct lista* poligono,struct lista** listaTriangulos); }
      else { ¿¿¿???}
    }
  }
}
