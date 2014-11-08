/**
 * @file    Peterson.c
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
#define ITER		1000
#define NHILOS	2

typedef unsigned char BOOLEAN;
typedef enum{
	PRIMERO, SEGUNDO
} TURNO;

BOOLEAN P1QuiereEntrar, P2QuiereEntrar;
TURNO TurnoProceso;
double contador = 0.0;

void * sumador1(void *p);
void * sumador2(void *p);

int
main(void)
{
	pthread_t hilos[NHILOS]; /* Creacion del vector de hilos */
	int status, i, v[NHILOS];
	extern double contador;
	extern BOOLEAN P1QuiereEntrar, P2QuiereEntrar;
	
	/* Inicializacion de las variables */
	P1QuiereEntrar = FALSE;
	P2QuiereEntrar = FALSE;
	TurnoProceso = PRIMERO;
	/* La diferencia con Dekker es que no se inicializa la variable 'hilos' */
  for(i=0;i<NHILOS;i++){
  	v[i] = i;
  }

	/* Creacion de los dos hilos */
	if((status = pthread_create(&hilos[0], NULL, sumador1, (void *) &v[0]))){
		exit(status);
	}
	if((status = pthread_create(&hilos[1], NULL, sumador2, (void *) &v[1]))){
		exit(status);
	}

	/* Espera a que finalicen. */
	for(i=0;i<NHILOS;i++){
		pthread_join(hilos[i], NULL);
	}

	/* Resultado final. */
	fprintf(stdout, "%f\n", contador);
	
	return(0);
}

void * sumador1(void *p)
{
	double x = 1.0, l;
	extern double contador;
	extern BOOLEAN P1QuiereEntrar, P2QuiereEntrar;
	extern TURNO TurnoProceso;
	int *id, i;

	id = (int *) p;

	for(i=0;i<ITER;i++){
		P1QuiereEntrar = TRUE;
		TurnoProceso = SEGUNDO;
		while(P2QuiereEntrar && TurnoProceso == SEGUNDO);

		/* Seccion critica */
		l = contador;
		fprintf(stdout, "Hilo %d: %f\n", *id, contador);
		l += x;
		contador = l;

		P1QuiereEntrar = FALSE;
	}

	pthread_exit(NULL);
}

void * sumador2(void *p)
{
	double x = 1.0, l;
	extern double contador;
	extern BOOLEAN P1QuiereEntrar, P2QuiereEntrar;
	extern TURNO TurnoProceso;
	int *id, i;

	id = (int *) p;

	for(i=0;i<ITER;i++){
		P2QuiereEntrar = TRUE;
		TurnoProceso = PRIMERO;
		while(P1QuiereEntrar && TurnoProceso == PRIMERO);

		/* Seccion critica */
		l = contador;
		fprintf(stdout, "Hilo %d: %f\n", *id, contador);
		l += x;
		contador = l;

		P2QuiereEntrar = FALSE;
	}

	pthread_exit(NULL);
}

