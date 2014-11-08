/**
 * @file    pract1a.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>
#include <math.h>

/*!\brief Calcula la raiz cuadrada de un  numero*/
int
main( int argc, char * argv[] )
{
  int codret=0; /*!< codigo de retorno del programa.*/
  float n;      /*!< numero al que se le calcula la raiz cuadrada.*/
  float raiz;   /*!< raiz cuadrada del numero.*/

  printf("Este programa calcula la raiz cuadrada de un numero. \n");

  printf("Dame el numero: ");
  scanf("%f",&n);
  
  raiz = sqrtf(n);

  printf("La raiz cuadrada de %8.3f es %8.3f,\n",n,raiz);

  return codret;
}
