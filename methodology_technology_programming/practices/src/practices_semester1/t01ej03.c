/**
 * @file    t01ej03.c
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

  float a,b,c,d;     /*los numeros que se van a comparar*/
  
  printf("Escribe los cuatro numeros\n");
  
  scanf("%f",&a);
  scanf("%f",&b);
  scanf("%f",&c);
  scanf("%f",&d);
  
  
  /*ahora se comprueban las condiciones necesarias*/

  /*los signos estan puestos de manera que no muestre 2 veces el resultado*/
  /*cuando se introduzcan varios numeros iguales*/


  if ((a <= b) && (a <= c) && (a <= d)){
    printf("menor = %f \n",a);
  }
  
  if ((b < a) && (b <= c) && (b <= d)){
    printf("menor = %f \n",b);
  }
  
  if ((c < a) && (c < b) && (c <= d)){
    printf("menor = %f \n",c);
  }
  
  if ((d < a) && (d < b) && (d < c)){
    printf("menor = %f \n",d);
  }
    
  if ((a >= b) && (a >= c) && (a >= d)){
    printf("mayor = %f \n",a);
  }

  if ((b > a) && (b >= c) && (b >= d)){
    printf("mayor = %f \n",b);
  }

  if ((c > a) && (c > b) && (c >= d)){
    printf("mayor = %f \n",c);
  }

  if ((d > a) && (d > b) && (d > c)){
    printf("mayor = %f \n",d);
  }
  
  return 0;
}
