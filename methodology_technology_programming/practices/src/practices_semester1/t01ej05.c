/**
 * @file    t01ej05.c
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

  int num;         /*numero que se va a analizar*/
  int i;           /*contador*/
  int suma = 0;        /*suma de los divisores del numero*/

  printf("Este programa calcula si un numero es o no perfecto\n"); 
  scanf("%d",&num);


  /*se calculan los divisores del numero y se van sumando*/
  
  for (i=1;i<num;i++){
    
    if (num%i == 0){
      suma = suma + i;
    }
  }
   
  
  /*se comprueba la condicion de numero perfecto*/   
  
  if (suma == num){
    printf ("El numero %d es perfecto\n",num);
  }
  else {
    printf ("El numero %d no es perfecto\n",num);
  }
  return 0;
}
