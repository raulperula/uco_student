/**
 * @file    ProCon.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define ITER	100
#define FIN	-1
#define N	10
#define C 2
#define P 4
#define NHILOS (P+C)

void *Productor(void *);
void *Consumidor(void *);

/* Bufer compartido. */
double bufer[N];

/* Semaforos. */
sem_t mutex, full, empty;
int p_index, c_index;

int
main(void)
{
	extern sem_t mutex, full, empty;
	extern int p_index, c_index;
	int status, i, v[NHILOS];
	double *p_suma, *c_suma, p_total = 0., c_total = 0.;
	pthread_t hilos[NHILOS];

	/* Inicializa semaforos y variables globales. */
	sem_init(&mutex, 0, 1);
	sem_init(&full, 0, 0);
	sem_init(&empty, 0, N);

	p_index = c_index = 0;
	srand(time(NULL));

	/* Inicia los hilos. */
	for(i=0;i<P;i++){
		v[i] = i;
		if(status = pthread_create(&hilos[i], NULL, Productor, (void *) &v[i])){
			exit(status);
		}
	}
	for(;i<(NHILOS);i++){
		v[i] = i-P;
		if(status = pthread_create (&hilos[i], NULL, Consumidor, (void *) &v[i])){
			exit(status);
		}
	}

	/* Espera a que finalicen. */
	for(i=0;i<P;i++){
		pthread_join(hilos[i], (void *) &p_suma);
		p_total += *p_suma;
	}

	/* Indica el fin a los consumidores. */
	for(i=0;i<C;i++){
		sem_wait(&empty);
		sem_wait(&mutex);

		bufer[p_index] = FIN;
		p_index = (p_index+1)%N;

		sem_post(&mutex);
		sem_post(&full);
	}

	/* Espera a que finalicen. */
	for(i=P;i<(NHILOS);i++){
		pthread_join(hilos[i], (void *) &c_suma);
		c_total += *c_suma;
	}

	printf("\nTotal producido: %f\n", p_total);
	printf("Total consumido: %f\n", c_total);
	
	return(0);
}

void *Productor(void *p)
{
	extern sem_t mutex, full, empty;
	extern double bufer[N];
	extern int p_index;
	int *it, i;
	double valor, *suma;

	it = (int *) p;

	suma = (double *) malloc(sizeof(double));
	*suma = 0.0;

	for(i=0;i<ITER;i++){
		/* Producir item */
		*suma += (valor = (double) (rand()%1000));

		sem_wait(&empty);
		sem_wait(&mutex);

		bufer[p_index] = valor;
		p_index = (p_index+1)%N;

		sem_post(&mutex);
		sem_post(&full);
	}
	
	pthread_exit ((void *) suma);
}

void *Consumidor(void *p)
{
	extern sem_t mutex, full, empty;
	extern double bufer[N];
	extern int c_index;
	int *it;
	double valor = 0, *suma;

	it = (int *) p;

	suma = (double *) malloc (sizeof(double));
	*suma = 0.0;

	while(valor != FIN){
		sem_wait(&full);
		sem_wait(&mutex);

		valor = bufer[c_index];
		c_index = (c_index+1)%N;

		sem_post(&mutex);
		sem_post(&empty);

		/* Consumir item. */
		*suma += valor;
	}

	*suma += 1.0;
	
	pthread_exit ((void *) suma);
}

