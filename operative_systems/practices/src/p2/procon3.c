/**
 * @file    procon3.c
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

#define N 100
#define P 3
#define C 2
#define NHILOS (P+C)

sem_t mutex;
sem_t entradas_ocupadas;
sem_t entradas_libres;

int vector[N];
int MAX_P=1000;
int MAX_C=1000;
int ind_p=0, total_p=0;
int ind_c=0, total_c=0;

void *productor(void *);
void *consumidor(void *);
int ProducirDato(int);
void EntrarDato(int, int);
int SacarDato(int);
int ConsumirDato(int, int *);

main()
{
	pthread_t hilos[P+C];
	int status, i, j, v[P], w[C];
	extern sem_t mutex, entradas_ocupadas, entradas_libres;
	extern total_p, total_c;
	srand(time(NULL));
	
	sem_init(&mutex, 0, 1);
	sem_init(&entradas_ocupadas, 0, 0);
	sem_init(&entradas_libres, 0, N);
	
	for(i=0;i<P;i++){
		v[i]=i;
		if (status =
	  	 pthread_create(&hilos[i], NULL, productor, (void *) &v[i]))
	  	 exit(status);
	}
	for(j=0;j<C;j++){
		w[j]=j;
		if (status =
	  	 pthread_create(&hilos[i], NULL, consumidor, (void *) &w[j]))
	  	 exit(status);
	}
	   
	/* Espera a que finalicen. */
  for (i = 0; i < (P+C); i++)
		pthread_join(hilos[i], NULL);
	
	printf("Total productor: %d\n", total_p);
	printf("Total consumidor: %d\n", total_c);
}

void *productor(void *p)
{
	extern sem_t mutex, entradas_ocupadas, entradas_libres;
	extern vector[N];
	extern ind_p, MAX_P, total_p;
	int dato;
	
	sem_wait(&mutex);
	while(MAX_P>0){
		sem_post(&mutex);
		dato = ProducirDato(100);
		sem_wait(&entradas_libres);
		sem_wait(&mutex);
		EntrarDato(dato, ind_p);
		total_p += dato;
		ind_p=(ind_p+1)%N;
		MAX_P--;
		sem_post(&mutex);
		sem_post(&entradas_ocupadas);
		sem_wait(&mutex);
	}
	sem_post(&mutex);
	
	pthread_exit(NULL);
}

void *consumidor(void *p)
{
	extern sem_t mutex, entradas_ocupadas, entradas_libres;
	extern ind_c, MAX_C, total_c;
	int i;
	int dato;
	
	sem_wait(&mutex);
	while(MAX_C>0){
		sem_post(&mutex);
		sem_wait(&entradas_ocupadas);
		sem_wait(&mutex);
		dato = SacarDato(ind_c);
		ind_c=(ind_c+1)%N;
		MAX_C--;
		sem_post(&mutex);
		sem_post(&entradas_libres);
		ConsumirDato(dato, &total_c);
		sem_wait(&mutex);
	}
	sem_post(&mutex);
	
	pthread_exit(NULL);
}

//Funciones auxiliares
int ProducirDato(int x)
{
	int n;
	n = rand()%x;
	
	return n;
}

void EntrarDato(int dato, int ind_p)
{
	extern vector[N];
	
	vector[ind_p] = dato;
}

int SacarDato(int ind_c)
{
	extern vector[N];
	
	return vector[ind_c];
}

int ConsumirDato(int dato, int *total)
{
	*total += dato;
}
