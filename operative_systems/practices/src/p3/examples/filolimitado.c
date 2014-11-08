/**
 * @file    filolimitado.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
/* Variables globales compartidas. */
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define N 		5
#define IZQUIERDA(x)	((x) !=0 ? (x)-1 : (N-1))
#define DERECHA(x)		(((x)+1)%N)
#define VIDA	10

typedef enum {
    PENSANDO, HAMBRIENTO, COMIENDO
} status;
status estado[N];
sem_t mutex, cmutex, s[N];

int comida = 0;

void Pensar(int);
void Comer(int);
void CogerTenedores(int);
void SoltarTenedores(int);
void Comprobar(int);
void *Cocinero(void *);

/* Programa principal. */
int main()
{
    extern status estado[N];
    extern sem_t mutex, s[N];
    pthread_t filosofo[N], cocinero;
    int i, v[N], value;
    void *Filosofo(void *);

    sem_init(&mutex, 0, 1);
    sem_init(&cmutex, 0 ,1);
    for (i = 0; i < N; i++)
	sem_init(&s[i], 0, 0);
    for (i = 0; i < N; i++)
	estado[i] = PENSANDO;

    // Inicia proceso cocinero
    if (value = pthread_create(&cocinero, NULL, Cocinero, (void *) NULL))
	exit(value);
    /* Iniciar filosfos. */
    for (i = 0; i < N; i++) {
	v[i] = i;
	if (value =
	    pthread_create(&filosofo[i], NULL, Filosofo, (void *) &v[i]))
	    exit(value);
    }

    // Espera fin de los filosofos
    for (i = 0; i < N; i++)
	pthread_join(filosofo[i], NULL);
}

/* Proceso filosofo. */
void *Filosofo(void *id)
{
    int indice, i;
    indice = *(int *) id;
    for (i = 0; i < VIDA; i++) {
	Pensar(indice);
	CogerTenedores(indice);
	Comer(indice);
	SoltarTenedores(indice);
    }
}

void CogerTenedores(int i)
{
    extern sem_t mutex, s[N];
    extern status estado[N];
    sem_wait(&mutex);
    estado[i] = HAMBRIENTO;
    Comprobar(i);
    sem_post(&mutex);
    sem_wait(&s[i]);
}

void SoltarTenedores(int i)
{
    extern sem_t mutex;
    extern status estado[N];
    sem_wait(&mutex);
    estado[i] = PENSANDO;
    Comprobar(IZQUIERDA(i));
    Comprobar(DERECHA(i));
    sem_post(&mutex);
}

void Comprobar(int i)
{
    extern sem_t s[N];
    extern status estado[N];
    if (estado[i] == HAMBRIENTO && estado[IZQUIERDA(i)] != COMIENDO &&
	estado[DERECHA(i)] != COMIENDO) {
	estado[i] = COMIENDO;
	sem_post(&s[i]);
    }
}

void Comer(int i)
{
    int s, c;
    extern int comida;

    // Espera a que haya comida
    c = random() % 5;
    for (;;) {
	sem_wait(&cmutex);
	if (comida > c) {
	    comida -= c;
	    sem_post(&cmutex);
	    break;
	}
	sem_post(&cmutex);
	sleep(1);
    }

    s = random() % 10;
    printf("Filosofo %d comiendo %d segundos\n", i, s);
    sleep(s);
}


void Pensar(int i)
{
    int s;
    s = random() % 10;
    printf("Filosofo %d pensando %d segundos\n", i, s);
    sleep(s);
}

void *Cocinero(void *p)
{
    extern int comida;
    extern sem_t cmutex;
    int c;
    for (;;) {
	// Crea comida
	c = random() % 100;
	sem_wait(&cmutex);
	comida += c;
	printf ("Preparada comida: %d\n", c);
	sem_post(&cmutex);
	sleep(5);
    }
}
