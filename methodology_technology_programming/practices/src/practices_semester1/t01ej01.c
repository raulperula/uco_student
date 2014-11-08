/**
 * @file    t01ej01.c
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
main(void){

  int horas;     /*almacena el numero de segundos de entrada, parcial y final*/
  int minutos;   /*almacena el numero de minutos parcial y final*/
  int segundos;  /*almacena el numero de segundos parcial y final*/

  printf("Introduce los segundos");
  scanf("%d",&segundos);
  
  minutos=segundos/60;
  segundos=segundos%60;
  horas=minutos/60;
  minutos=minutos%60;

  printf("%d horas, %d minutos, %d segundos\n",horas, minutos, segundos); 
  return 0;
}
