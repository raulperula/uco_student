/**
 * @file    t02ej03a.c
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
  int diffact1;    /*almacena la diferencia entre fact (por exceso) y num*/
  int diffact2;    /*almacena la diferencia entre fact (por defecto) y num*/
  
  while (fact <= num) {
    
    fact = (fact * i);
    
    if (fact == num){
       
      esfact = 1;
      printf("El factorial de %d es %d \n",num,i); 
    }  
    else {
         
      diffact1 = (fact - num);
      i++;  
    }
  }
  
  if (esfact == 0) {
    
    fact = (fact / i);
    diffact2 = (num - fact);
    
    if (diffact2 < diffact1) {
       
      i = (i-2);
    }
    else {
         
      i = (i-1);
    }
  
    printf("El factorial de %d no es exacto \n",num);
    printf("El factorial mas cercano a %d es %d \n",num,i);
  }

  return 0;     
}     
