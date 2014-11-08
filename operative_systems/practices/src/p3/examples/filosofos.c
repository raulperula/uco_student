/**
 * @file    fiosofos.c
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
#define VIDA	100

typedef enum {
    PENSANDO, HAMBRIENTO, COMIENDO
} status;
status estado[N];
sem_t mutex, s[N];

void Pensar(int);
void Comer(int);
void CogerTenedores(int);
void SoltarTenedores(int);
void Comprobar(int);

/* Programa principal. */
int main()
{
    extern status estado[N];
    extern sem_t mutex, s[N];
    pthread_t filosofo[N];
    int i, v[N], value;
    void *Filosofo(void *);

    sem_init(&mutex, 0, 1);
    for (i = 0; i < N; i++)
	sem_init(&s[i], 0, 0);
    for (i = 0; i < N; i++)
	estado[i] = PENSANDO;

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
    int s;

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
