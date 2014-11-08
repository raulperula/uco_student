/**
 * @file    Lamport.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define TRUE		1
#define FALSE		0
#define ITER		100
#define NHILOS	4

typedef unsigned char BOOLEAN;

BOOLEAN Elegido[NHILOS];
int ticket[NHILOS];
double contador = 0;

void * sumador(void *);
int max(int *);

int
main(void)
{
  pthread_t hilos[NHILOS];
  int status, i, v[NHILOS];
  extern double contador;
  extern BOOLEAN Elegido[NHILOS];
  extern int ticket[NHILOS];

	/* Inicializacion del vector */
  for(i=0;i<NHILOS;i++){
  	v[i] = i;
  }
  
  /* Se inicializan las variables globales */
  for(i=0;i<NHILOS;i++){
    Elegido[i] = FALSE;
    ticket[i] = 0;
  }
  
  /* Ejecuta NHILOS hilos. */
  for(i=0;i<NHILOS;i++){
    if((status = pthread_create(&hilos[i], NULL, sumador, (void *) &v[i]))){
			exit(status);
		}
  }

  /* Espera a que finalicen. */
  for(i=0;i<NHILOS;i++){
    pthread_join(hilos[i], NULL);
	}

  /* Resultado final. */
  fprintf(stdout, "%f\n", contador);
  
  return(0);
}

void * sumador(void *p)
{
  double x = 1.0, l;
  extern double contador;
  extern BOOLEAN Elegido[NHILOS];
  extern int ticket[NHILOS];
  int *I; 
  int i, j;

  I = (int *) p;

  for(i=0;i<ITER;i++){
		Elegido[*I] = TRUE;
		ticket[*I] = max(ticket)+1;
		Elegido[*I] = FALSE;

		for(j=0;j<NHILOS;j++){
		  while(Elegido[j]);
		  while((ticket[j] != 0) && ((ticket[j] < ticket[*I]) || ((ticket[j] == ticket[*I]) && (j < (*I)))));
		}
		
		/* Seccion critica */
		l = contador;
		fprintf(stdout, "Hilo %d: %f\n", *I, contador);
		l += x;
		contador = l;
		
		ticket[*I] = 0;
  }

  pthread_exit(NULL);
}

/* Funcion auxiliar que calcula el maximo de un vector */
int max(int *vector)
{
	int max = vector[0];
	int i;

	for(i=1;i<NHILOS;i++){
		if(vector[i] > max){
			max = vector[i];
		}
	}

	return(max);
}
