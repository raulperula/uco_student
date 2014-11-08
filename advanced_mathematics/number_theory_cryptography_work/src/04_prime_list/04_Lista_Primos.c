/**
 * @file    04_Lista_Primos.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>
#include <math.h>
#define N 200000

int
main(void)
{
  int numero;  /*numero proprocionado por el usuario*/
  int listaprimos[N];  /*almacena los primos menores que el numero*/
  int primo = 2;  /*posible primo*/
  int esprimo = 0;  
  int i,j;  /*variables contador*/

  printf("Este programa calcula todos los primos inferiores a un numero ");
  printf("natural \nmayor que 1 dado por el usuario: \n");
  printf("Introduce un numero: ");
  scanf("%d",&numero);         
          
  /*inicializamos la lista de primos*/        
  for(i=0;i<N;i++){
    listaprimos[N] = 0;
  }
  listaprimos[0] = 2;
  i=0;
  
  /*vamos completando la lista*/
  while (primo <= numero){
    primo++;
    esprimo = 1;
    
    for(j=0;j<=i;j++){
      if((primo % listaprimos[j]) == 0) esprimo = 0;
    }
    
    if(esprimo == 1){
      i++;         
      listaprimos[i] = primo;    
    }          
  }
  
  printf("Los primos hasta %d son: \n",numero);
  for(j=0;j<=i;j++) printf("%03d ",listaprimos[j]);
  
  getchar();
  getchar();    
}
