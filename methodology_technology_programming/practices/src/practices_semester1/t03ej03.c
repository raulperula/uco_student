/**
 * @file    t03ej03.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>


int genera_numero(void);
int comprueba_numero_repetido(int num, int primitiva[]);
int almacena_numero(int num, int primitiva[]);


int
main(void)
{
          
  int primitiva[49] = {0};  /*vector que almacena los posibles resultados*/
  int apuesta;              /*almacena cada una de las apuestas*/         
  int num;                  /*numero generado aleatoriamente*/
  int i;                    /*contador*/

  printf("Este programa hace una apuesta aleatoria de primitiva \n");

  for (i=0;i<6;i++) {
      
    num = genera_numero();
    if (comprueba_numero_repetido(num, primitiva) == 0) {
       
       almacena_numero(num, primitiva);
    }
    
    else {
        i--;
    }     
    
  } 
  
  return 0;        
}


int genera_numero(void)
{
  int aleatorio   /*numero aleatorio comprendido entre 0 y 49*/
  
  random(aleatorio);
  
  return aleatorio;  
}

int comprueba_numero_repetido(int num, int primitiva[])
{
    
}

int almacena_numero(int num, int primitiva[])
{
    
}
