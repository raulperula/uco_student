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
 
#include<miscelanea.h>

int es_primo(int n){
  int i;
  int marca=0;
  for(i=0;i<sqrt(n);i++){
    if((n%i)==0){
      marca=1;
      break;
    }
  }
  return marca;
}
	
void randGenerator(int n,int* rn){
  int i
  int max;
  srand((int)time(&t));
  rn=(int*)malloc(n*sizeof(int));
  printf("Dame el maximo valor de los numeros aleatorios:");
  scanf("%d",&max);
  for(i=0;i<n;i++){
    rn[i]=(rand()%max)+1;
  }
}
