/**
 * @file    t02ej03b.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>


int factorial(int num, int salida[2]);

int
main(void)
{
  int num;            /*numero que se va a analizar*/
  int salida[2]={0};  /*vector que almacena esfact, i*/
   
  printf("Dame el numero para analizar \n");
  scanf("%d",&num);

  int factorial(int num, int salida[2]);

  if (salida[1] == 1) {
  
    printf("El numero %d es factorial de %d",num,salida[0]); 
  }
  else {
    
    printf("El numero %d no es factorial exacto \n",num);
    printf("El factorial mas cercano a %d es %d \n",num,salida[0]);
  }
  
  system("PAUSE");    
}



int factorial(int num, int salida[2])  
                        /*Averigua si num es igual a fact y si no devuelve*/
                        /*el factorial inmediatamente menor*/
{
  int fact = 1;    /*compara el factorial de i con num*/
  int esfact = 0;  /*int que vale 1 si i es factorial de num o 0 si no lo es*/
  int i = 1;       /*variable usada como contador y como factorial*/
  int diffact1;    /*almacena la diferencia entre fact (por exceso) y num*/
  int diffact2;    /*almacena la diferencia entre fact (por defecto) y num*/
  
  while (fact <= num) {
    
    fact = (fact * i);
    
    if (fact == num){
       
      esfact = 1;
      salida[1] = 1; 
      printf("El numero %d es factorial de %d \n",num,i);
    }  
    else {
         
      diffact1 = (fact - num);   
      i++;  
    }
  }
  
  if (esfact == 0) {
    
    salida[1] = 0;
    fact = (fact / i);
    diffact2 = (num - fact);
    
    if (diffact2 < diffact1) {
       
      salida[0] = (i-2);
    }
    else {
         
      salida[0] = (i-1);
    }
  }  
  
  return salida[2];
}     

