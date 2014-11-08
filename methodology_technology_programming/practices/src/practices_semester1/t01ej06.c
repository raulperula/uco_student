/**
 * @file    t01ej06.c
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
  
  int year;     /*agno que se quiere analizar si es o no bisiesto*/
  

  printf("Esribe el agno: ");
  scanf("%d",&year);

  /*se comprueban las condiciones de agno bisiesto*/

  if (year%4 == 0 && year%100 != 0){
    printf("El agno %d es bisiesto\n",year);
  }

  else  if (year%400 == 0){
    printf("El agno %d es bisiesto\n",year);
  } 
  
  else{
    printf("El agno %d no es bisiesto\n",year);
  }

  return 0;
}
