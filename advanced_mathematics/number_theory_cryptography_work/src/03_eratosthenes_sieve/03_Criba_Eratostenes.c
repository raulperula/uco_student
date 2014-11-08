/**
 * @file    03_Criba_Eratostenes.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>
#define N 200000


int
main(void)
{
  int numero;      /*numero proporcionado por el usuario*/          
  int id;          /*variable que valdra 0 si un numero de la criba aun no 
                     ha sido tachado, 1 si ya ha sido tachado, o 2 si se ha 
                     determinado que es primo*/          
  int criba[N][2]; /*matriz que almacenara los numeros de la criba y su estado*/   
  int i,j;         /*variables contador*/          
  
  printf("Este programa calcula la Criba de Eratostenes hasta un numero \n");
  printf("dado por el usuario. \n");
  printf("Introduce un numero natural mayor de 2: ");
  scanf("%d",&numero);
  
  /*inicializamos la criba*/
  for(i=0;i<numero-1;i++){
    criba[i][0] = i+2;
    criba[i][1] = 0;
  }
  
  /*hacemos el proceso de criba para n=2, ya que es el unico termino que no
    verifica el algoritmo de abajo*/
  criba[0][1] = 2;
  for(i=2;i<numero-1;i=i+2) criba[i][1] = 1;
  
  /*continuamos el proceso de criba desde el 3*/
  for(i=1;i<numero-1;i++){
    if (criba[i][1] == 0){
      criba[i][1] = 2;
      for(j=(2*criba[i-1][0]);j<numero-1;j=j+criba[i][0]){
        criba[j][1] = 1;
      }
    }
  }

  printf("Criba de Eratostenes del 2 al %d: \n",numero);
  
  for(i=0;i<numero-1;i++){
    if(criba[i][1] == 2) printf("%03d ",criba[i][0]);
  }
                   
  getchar();
  getchar();        
}
