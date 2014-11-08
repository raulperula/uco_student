/**
 * @file    hilos.c
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

double contador = 0.0;

#define ITER	1000
#define NHILOS	3

main()
{
	pthread_t hilos[NHILOS];
	int status, i, v[NHILOS];
	extern double contador;
	void * sumador(void *);

	/* Ejecuta NHILOS hilos. */
	for (i = 0; i < NHILOS; i++) {
		v[i] = i;
		if (status = pthread_create(&hilos[i], NULL, sumador, (void *) &v[i]))
			exit(status);
	}

	/* Espera a que finalicen. */
	for (i = 0; i < NHILOS; i++)
		pthread_join(hilos[i], NULL);
	
	/* Resultado final. */
	fprintf(stdout, "%f\n", contador);
}

void * sumador(void *p)
{
	double x = 1.0, l;
	extern double contador;
	int *id, i;

	id = (int *) p;

	for (i = 0; i < ITER; i++) {
		l = contador;
		fprintf(stdout, "Hilo %d: %f\n", *id, contador);
		l += x;
		contador = l;
	}

	pthread_exit(NULL);
}

