/**
 * @file    procon2.c
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
#define P 2
#define C 2
#define NHILOS (P+C)
#define FIN -1

//Semaforos
sem_t mutex;
sem_t entradas_ocupadas;
sem_t entradas_libres;

double buffer[N]; //Buffer compartido
int MAX_P = 1000;
int MAX_C = 1000;
int ind_p = 0, ind_c = 0;
double total_p = 0., total_c = 0.;

void *productor(void *);
void *consumidor(void *);
int ProducirDato(int);
void EntrarDato(int, int);
int SacarDato(int);
int ConsumirDato(int, double *);

main()
{
	pthread_t hilos[P+C];
	int status, i, j, v[P], w[C];
	extern sem_t mutex, entradas_ocupadas, entradas_libres;
	extern double total_p, total_c;
	extern double buffer[N];
	double *suma_p, *suma_c;
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
	for(;i<P+C;i++){
		v[j]=j+P;
		if (status =
	  	 pthread_create(&hilos[i], NULL, consumidor, (void *) &v[i]))
	  	 exit(status);
	}
	   
	/* Espera a que finalicen. */
  for (i = 0; i < (P+C); i++){
		pthread_join(hilos[i], NULL);
		total_p += *suma_p;
	}
	
	/* Indica el fin a los consumidores. */
  for (i = 0; i < C; i++)
  {
    sem_wait (&entradas_libres);
    sem_wait (&mutex);

    buffer[ind_p] = FIN;
    ind_p = (ind_p+1)%N;

    sem_post (&mutex);
    sem_post (&entradas_ocupadas);
  }

  /* Espera a que finalicen. */
  for (i = P; i < P+C; i++)
    {
      pthread_join(hilos[i], (void *) &suma_c);
      total_c += *suma_c;
    }
	
	printf("Total productor: %d\n", total_p);
	printf("Total consumidor: %d\n", total_c);
}

void *productor(void *p)
{
	extern sem_t mutex, entradas_ocupadas, entradas_libres;
	extern double buffer[N];
	extern int ind_p, MAX_P;
	extern double total_p;
	int dato;
	double valor, *suma;
	
	suma = (double*) malloc(sizeof(double));
	*suma = 0.0;
	
	sem_wait(&mutex);
	while(MAX_P>0){
		sem_post(&mutex);
		dato = ProducirDato(100);
		sem_wait(&entradas_libres);
		sem_wait(&mutex);
		EntrarDato(dato, ind_p);
		total_p += dato;
		ind_p = (ind_p+1)%N;
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
	extern int ind_c, MAX_C;
	extern double total_c;
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
	extern double buffer[N];
	
	buffer[ind_p] = dato;
}

int SacarDato(int ind_c)
{
	extern double buffer[N];
	
	return buffer[ind_c];
}

int ConsumirDato(int dato, double *total)
{
	*total = *total+dato;
}

