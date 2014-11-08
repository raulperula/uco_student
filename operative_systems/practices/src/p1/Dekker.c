/**
 * @file    Dekker.c
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
	for(i=0;i<NHILOS;i++){
		hilos[i] = i+1;
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
		while(P2QuiereEntrar){
			if(TurnoProceso == SEGUNDO){
				P1QuiereEntrar = FALSE;
				while(TurnoProceso == SEGUNDO);
				P1QuiereEntrar = TRUE;
			}
		}
		
		/* Seccion critica */
		l = contador;
		fprintf(stdout, "Hilo %d: %f\n", *id, contador);
		l += x;
		contador = l;

		TurnoProceso = SEGUNDO;
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

	/* Seccion critica */
	for(i=0;i<ITER;i++){
		P2QuiereEntrar = TRUE;
		while(P1QuiereEntrar){
			if(TurnoProceso == PRIMERO){
				P2QuiereEntrar = FALSE;
				while(TurnoProceso == PRIMERO);
				P2QuiereEntrar = TRUE;
			}
		}
		
		l = contador;
		fprintf(stdout, "Hilo %d: %f\n", *id, contador);
		l += x;
		contador = l;
	
		TurnoProceso = PRIMERO;
		P2QuiereEntrar = FALSE;
	}

	pthread_exit(NULL);
}

