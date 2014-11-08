/**
 * @file    02_Factorizacion.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>
#define N 100

int genera_primo(int primo);


int
main(void)
{
  
  int numero;  /*numero dado por el usuario*/
  int listaprimos[N];  /*almacena los factores primos del numero*/
  int j,i = 0;  /*almacenan los factores primos en el vector lista_primos*/
  int primo = 1;  /*almacena posibles factores primos*/
  
  printf("Este programa descompone un numero dado por el usuario en factores");
  printf(" primos. \n");
  printf("Introduce un numero mayor que 1: ");
  scanf("%d",&numero);
  printf("\n");
  printf("%d: {",numero);
  
  if (numero == 1) listaprimos[0] = 1;
           
  /*se genera un primo, se comprueba si es divisible, si lo es se anota y 
    se vuelve a comprobar, si no lo es se genera un nuevo primo y se repite 
    el proceso hasta el final*/
  while(numero != 1){
    primo = genera_primo(primo);
    if ((numero % primo) == 0){
      numero = numero / primo;
      listaprimos[i] = primo;
      i++;
      primo--;
    }    
    if (numero == 1) break;       
  }
  
  /*se muestran los resultados*/
  for(j=0;j<i-1;j++){
    printf("%d,",listaprimos[j]);
  }
  printf("%d}",listaprimos[j]);
  
  getchar();
  getchar();                    
}



/*genera el siguiente primo a un primo dado y lo devuelve como parametro*/
int genera_primo(int primo)
{
  int i = 1;
  int esprimo = 0;
 
  do{
    primo++;
    while ((i < primo) && (esprimo == 0)) {
      if ((primo % i) == 0) {
        esprimo = 1;
      }
      i++;
    }
  }while(esprimo == 0); 
  return primo;
}






 

