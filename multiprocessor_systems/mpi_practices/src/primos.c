/**
 * @file    primos.c
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
#include <math.h>
#include "mpi.h"

#define LIMITE 10000000
#define MASTER 0

// Funcion para comprobar si un numero es primo
int esprimo(int n) {
	int i, raiz;
	
	if(n > 10){
		raiz = (int) sqrt(n);
		for(i=3;i<=raiz;i=i+2){
			if((n%i) == 0){
				return 0;
			}
		}
		return 1;
	}
	else{
   		return 0;
	}
}

int main(int argc, char *argv[])
{
	int ntasks, rank, n, pc, pcsum, primo, maxprimo, mystart, stride;
	double t_ini, t_fin;
	FILE * f;
	
	MPI_Init(&argc, &argv);
	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
	
	// Inicializar variables
	t_ini = MPI_Wtime();
	mystart = (rank*2)+1;
	stride = ntasks*2;
	pc = 0;
	primo = 0;
	
	// Abrir fichero que contendra los primos
	f = fopen("primos.txt", "w+");

	// Master
	if (rank == MASTER) {
		printf("Usando %d tareas para escanear %d numeros:\n", ntasks, LIMITE);
		pc = 4;
		for(n=mystart;n<=LIMITE;n=n+stride){
			if(esprimo(n)){
				pc++;
				primo = n;

				fprintf(f, "%d\n", primo);
			}
		}
		
		MPI_Reduce(&pc, &pcsum, 1, MPI_INT, MPI_SUM, MASTER, MPI_COMM_WORLD);
		MPI_Reduce(&primo, &maxprimo, 1, MPI_INT, MPI_MAX, MASTER, MPI_COMM_WORLD);
		
		t_fin = MPI_Wtime();
		
		printf("\nEl mayor numero primo es: %d. Numero total de primos obtenidos: %d\n", maxprimo, pcsum);
		printf("\nTiempo de computo: %.2lfs\n", t_fin-t_ini);
	}

	// Hijos
	if(rank > MASTER){
		for(n=mystart;n<=LIMITE;n=n+stride){
			if(esprimo(n)){
				pc++;
				primo = n;

				fprintf(f, "%d\n", primo);
			}
		}
		MPI_Reduce(&pc, &pcsum, 1, MPI_INT, MPI_SUM, MASTER, MPI_COMM_WORLD);
		MPI_Reduce(&primo, &maxprimo, 1, MPI_INT, MPI_MAX, MASTER, MPI_COMM_WORLD);
	}
	
	// Se cierra el fichero
	fclose(f);

	MPI_Finalize();
}
