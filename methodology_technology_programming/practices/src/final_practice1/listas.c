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
#include"miscelanea.h"

void nuevoelem(struct lista* poligono, int nlados){

  poligono=(struct lista *)malloc(sizeof(struct lista));
  poligono->nlados=nlados;
  poligono->puntos=(int*)malloc(nlados*sizeof(int));
}

void insertarLista(struct lista* poligono,struct lista ** listaTriangulos){
  poligono->sig=*listaTriangulos;
  *listaTriangulos=poligono;
}

void borrarElemento(struct lista** listaTriangulos){
  struct lista* apuntador;
  struct lista* ant;
  apuntador=*listaTriangulos
  ant=apuntador;
  while(apuntador!=NULL){
    if((calcularPerimetro(struct lista* apuntador))<400){
      if(apuntador==*listaTriangulos){
        *listaTriangulos=*listaTriagulos->sig;
        free(apuntador);
        apuntador=*listaTriangulos
        ant=apuntador;
      }
      else{
        ant->sig=apuntador->sig;
        free(apuntador);
        apuntador=ant->sig;
      }
    }
    else{
        ant=apuntador;
        apuntador=apuntador->sig;
    }
  }
}
