/**
 * @file    filosofoscocina.c
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

#define N 5
#define CANT 100

typedef enum {PENSANDO, HAMBRIENTO, COMIENDO} status1;
status1 estado[N];

int comida = 0;

sem_t mutex, s[N], comido;

void* Filosofo(void*);
void* Cocina(void *);
void Pensar(int);
void Comer(int);
void CogerTenedores(int);
void SoltarTenedores(int);
void Comprobar(int);
int Izquierda(int);
int Derecha(int);
int ProducirComida();

main()
{
  pthread_t hilos[N];
  extern status1 estado[N];
  extern sem_t mutex, s[N];
  int i;
  int status, v[N];
  srand(time(NULL));
  
  //Inicializacion de los semaforos
  sem_init(&mutex, 0, 1);
  for(i=0;i<N;i++){
    sem_init(&s[i], 0, 0);
  }
  sem_init(&comido, 0, 1);
  
  //Inicializacion de los estados
  for(i=0;i<N;i++){
  	estado[i] = PENSANDO;
  }
  
  //Creamos los hilos
  v[0] = 0;
  if(status = pthread_create(&hilos[i], NULL, Cocina, (void *) &v[0])){
		exit(status);
	}
	  
  for(i=0;i<N;i++){
  	v[i] = i;
  	if(status = pthread_create(&hilos[i], NULL, Filosofo, (void *) &v[i])){
	  	exit(status);
	  }
	}
	
	/* Espera a que finalicen. */
  for(i=0;i<N;i++){
		pthread_join(hilos[i], NULL);
	}

}

void* Filosofo(void *p)
{
	int i;
	int *I;
	
	I = (int *) p;
	
	for(i=0;i<N;i++){
		Pensar(*I);
		CogerTenedores(*I);
		Comer(*I);
		SoltarTenedores(*I);
	}
	pthread_exit(NULL);
}

void* Cocina(void *p)
{
	int i;
	int valor;
	extern comida;
	extern sem_t mutex;
	
	sleep(5);
	comida += ProducirComida();
	
	sem_getvalue(&comido, &valor);
	
	if((comida>0) && (valor<=0)){
		sem_post(&comido);
	}
	
	pthread_exit(NULL);
}

void Pensar(int i)
{
	sleep(random()%10);
	printf("Filosofo %d Pensando\n", i);
}

void Comer(int i)
{
	extern comida;
	int j, U;
	
	U = rand()%6;
	
	for(j=0;j<U;j++){
		if(comida >= U){
			comida--;
			printf("Filosofo %d Come y Queda %d\n", i, comida);
		}
		else{
			sem_wait(&comido);
			comida--;
		}
	}
}

void CogerTenedores(int i)
{
	extern sem_t mutex, s[N];
	extern status1 estado[N];
	
	sem_wait(&mutex);
	estado[i] = HAMBRIENTO;
	Comprobar(i);
	sem_post(&mutex);
	sem_wait(&s[i]);
}

void SoltarTenedores(int i)
{
	extern sem_t mutex, s[N];
	extern status1 estado[N];
	
	sem_wait(&mutex);
	estado[i] = PENSANDO;
	Comprobar(Izquierda(i));
	Comprobar(Derecha(i));
	sem_post(&mutex);
}

void Comprobar(int i)
{
	extern sem_t mutex, s[N];
	extern status1 estado[N];
	
	if((estado[i] == HAMBRIENTO) && (estado[Izquierda(i)] != COMIENDO) && (estado[Derecha(i)] != COMIENDO)){
		estado[i] = COMIENDO;
		sem_post(&s[i]);
	}
}

int Izquierda(int x)
{
	if(x > 0){
		return(x-1);
	}
	else{
		return(N-1);
	}
}

int Derecha(int x)
{
	return((x+1)%N);
}

int ProducirComida()
{
	int n;
	n = rand()%101;
	
	return n;
}

