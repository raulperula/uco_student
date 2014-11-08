/**
 * @file    miscelanea.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include"miscelanea.h"


void imprimirListaTriangulos(struct lista* listaTriangulos){
  int i;
  int j;
  int pos=1;
  int marca=0;
  struct lista* apuntador;
  apuntador=listaTriangulos;
  while(apuntador!=NULL){
    printf("las coordenadas del triangulo %d son:\n",pos);
    while(marca!=6){
        printf("(%d %d)",apuntador->puntos[i],apuntador->puntos[j];
        i=i+2;
        j=j+2;
    }
    printf("\n");
    apuntador=apuntador->sig;
  }
}

int calcularPerimetro(struct lista* listaTriangulos){
  int perimetro;
  int aux1;
  int aux2;
  int sum1, sum2, sum3;
  struct lista* apuntador;
  int i;
  int j;
  int k;
  apuntador=listaTriangulos;
  aux1=pow(apuntador->puntos[0],2)-pow(apuntador->puntos[2],2);
  aux2=pow(apuntador->puntos[1],2)-pow(apuntador->puntos[3],2);
  sum1=aux1-aux2;
  aux1=pow(apuntador->puntos[0],2)-pow(apuntador->puntos[4],2);
  aux2=pow(apuntador->puntos[1],2)-pow(apuntador->puntos[5],2);
  sum2=aux1-aux2;
  aux1=pow(apuntador->puntos[2],2)-pow(apuntador->puntos[4],2);
  aux2=pow(apuntador->puntos[3],2)-pow(apuntador->puntos[5],2);
  sum3=aux1-aux2;
  perimetro=sqrt(sum1)+sqrt(sum2)+sqrt(sum3);
  return perimetro;
}



