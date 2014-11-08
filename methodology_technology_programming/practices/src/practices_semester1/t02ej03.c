/**
 * @file    t02ej03.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>


int factorial(int num);

int
main(void)
{
  int num;     /*numero que se va a analizar*/

  printf("Dame el numero para analizar \n");
  scanf("%d",&num);

  factorial(num);

  system("PAUSE");    
}



int factorial(int num)  /*Averigua si num es igual a fact y si no devuelve*/
                        /*el factorial inmediatamente menor*/
{
  int fact = 1;    /*compara el factorial de i con num*/
  int esfact = 0;  /*int que vale 1 si i es factorial de num o 0 si no lo es*/
  int i = 1;       /*variable usada como contador*/
  
  while (fact <= num) {
    
    fact = (fact * i);
    
    if (fact == num){
       
      esfact = 1; 
      printf("El numero %d es factorial de %d \n",num,i);
      break;
    }  
    else {
         
      i++;  
    }
  }
  
  if (esfact == 0) {
    
    i = (i-2);
    printf("El numero %d no es el resultado de ningun factorial \n",num);
    printf("El factorial menor mas cercano a %d es %d! \n", num,i); 
  }
}     
