/**
 * @file    procon1.c
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
#include <time.h>
#include <semaphore.h>

#define N 			100
#define NHILOS	2
#define MAX_P		1000
#define MAX_C		1000

void *productor(void *p);
void *consumidor(void *p);
int ProducirDato(int x);
void EntrarDato(int, int);
int SacarDato(int);
int ConsumirDato(int, int *);

/* Creacion de los semaforos */
sem_t mutex, entradas_ocupadas, entradas_libres;

int buffer[N];

int
main(void)
{
	pthread_t hilos[NHILOS];
	int status, i, v[NHILOS];
	extern sem_t mutex, entradas_ocupadas, entradas_libres;
	
	srand(time(NULL));
	
	sem_init(&mutex, 0, 1);
	sem_init(&entradas_ocupadas, 0, 0);
	sem_init(&entradas_libres, 0, N);

	for(i=0;i<NHILOS;i++){
		v[i] = i;
	}
	
	if(status = pthread_create(&hilos[0], NULL, productor, (void *) &v[0])){
		exit(status);
	}
	if(status = pthread_create(&hilos[1], NULL, consumidor, (void *) &v[1])){
		exit(status);
	}
	   
	/* Espera a que finalicen. */
  for(i=0;i<NHILOS;i++){
		pthread_join(hilos[i], NULL);
	}
	
	return(0);
}

void * productor(void *p)
{
	extern sem_t mutex, entradas_ocupadas, entradas_libres;
	extern int buffer[N];
	int dato, total_p = 0;
	int i;
	int ind_p = 0;
	
	for(i=0;i<MAX_P;i++){
		dato = ProducirDato(100);
		
		sem_wait(&entradas_libres);
		sem_wait(&mutex);
		
		EntrarDato(dato, ind_p);
		total_p += dato;
		
		sem_post(&mutex);
		sem_post(&entradas_ocupadas);
		
		ind_p = (ind_p+1)%N;
	}
	
	printf("Total productor: %d\n", total_p);
	
	pthread_exit(NULL);
}

int ProducirDato(int x)
{
	int n;
	n = rand()%x;
	
	return n;
}

void EntrarDato(int dato, int ind_p)
{
	extern int buffer[N];
	
	buffer[ind_p] = dato;
}

void * consumidor(void *p)
{
	extern sem_t mutex, entradas_ocupadas, entradas_libres;
	int i;
	int ind_c = 0;
	int dato, total_c = 0;
	
	for(i=0;i<MAX_C;i++){
		sem_wait(&entradas_ocupadas);
		sem_wait(&mutex);
		
		dato = SacarDato(ind_c);
		
		sem_post(&mutex);
		sem_post(&entradas_libres);
		
		ConsumirDato(dato, &total_c);
		ind_c=(ind_c+1)%N;
	}
	printf("Total consumidor: %d\n", total_c);
	
	pthread_exit(NULL);
}

int SacarDato(int ind_c)
{
	extern int buffer[N];
	
	return buffer[ind_c];
}

int ConsumirDato(int dato, int *total)
{
	*total += dato;
}

