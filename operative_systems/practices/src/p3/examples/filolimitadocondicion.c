/**
 * @file    filolimitadocondicion.c
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
sem_t mutex, s[N];

pthread_cond_t no_comida;
pthread_mutex_t cmutex;

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
    
    pthread_cond_init(&no_comida, NULL);  
    pthread_mutex_init(&cmutex, NULL);

    sem_init(&mutex, 0, 1);
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
    extern sem_t s[N], mutex;
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
    extern pthread_mutex_t cmutex;
    extern pthread_cond_t no_comida;

    // Espera a que haya comida
    c = random() % 5;
    for (;;) {
        pthread_mutex_lock (&cmutex);
	if (comida > c) {
	    comida -= c;
	    printf ("Filosofo %d comera %d unidades de %d\n", i, c, comida+c);
	    pthread_mutex_unlock(&cmutex);
	    break;
	}
	printf ("Filosofo %d se bloquea en espera de comida\n", i);
	pthread_cond_wait (&no_comida, &cmutex);
	pthread_mutex_unlock(&cmutex);	
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
    extern pthread_mutex_t cmutex;
    int c;
    for (;;) {
	// Crea comida
	c = random() % 10;
	pthread_mutex_lock(&cmutex);
	comida += c;
	printf ("Preparada comida: %d\n", c);
	pthread_cond_broadcast (&no_comida);
	pthread_mutex_unlock(&cmutex);
	sleep(10);
    }
}
