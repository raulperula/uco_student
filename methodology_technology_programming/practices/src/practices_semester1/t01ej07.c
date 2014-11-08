/**
 * @file    t01ej07.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>


int
main(void)

{

  int num;        /*numero que se va a descomponer*/
  int coc;        /*cociente parcial usado en el algoritmo de descomposicion*/
  int a;          /*variable contador*/
  int i = 0;
  int base = 0;   /*incrementa el exponente de la base del numero (10^base)*/
  int vector[10] = {0}; /*vector que almacena la descomposicion del numero*/



  printf("Dame el numero para descomponer: ");
  scanf("%d",&num);

  coc = num;     

  while (coc != 0){
    printf("%d %d %d %d\n", vector[0],coc,base,i);

    vector[i] = ((coc%10) * 10 ^ (base));
    coc = (coc/10);
    base++;
    i++;

    printf("%d %d %d %d\n", vector[i],coc,base,i);
  }

  
  printf("La descomposicion de %d es: ",num);

  for (a=0;a < i;a++){

    printf("%d + ",vector[a]);
  }
  
  printf("\n");

  return 0;
}
