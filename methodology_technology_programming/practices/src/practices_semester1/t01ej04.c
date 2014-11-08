/**
 * @file    t01ej04.c
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
  
  int n;   /*numero limite de la suma*/
  int x;   /*resultado de la suma de los n primeros nums enteros*/

  printf("Calcular la suma de los enteros del 1 al...");
  scanf("%d",&n);

  x = (n*(n+1))/2; /*algoritmo de la suma de los n primeros enteros*/

  printf("La suma de los enteros del 1 al %d es %d \n",n,x);

  return 0;
}

  
