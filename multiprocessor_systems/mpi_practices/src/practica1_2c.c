/**
 * @file    practica1_2c.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

#include <stdio.h>
#include <mpi.h>

#define N 50

int main(int argc, char** argv)
{
	int myrank, size, i;
	char cad1[N], cad2[N];
	MPI_Status estado;
	
	MPI_Init(&argc, &argv); // comienzo zona MPI
	
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank); // id del proceso
	MPI_Comm_size(MPI_COMM_WORLD, &size); // numero de procesos
	
	if(myrank == 0){
		sprintf(cad1, "Hola mundo desde %d\n", myrank);
		MPI_Bcast(cad1, N, MPI_CHAR, 0, MPI_COMM_WORLD);
	}
	else{
		MPI_Bcast(cad2, N, MPI_CHAR, 0, MPI_COMM_WORLD);
		printf("Hijo %d: %s", myrank, cad2);
	}
	
	MPI_Finalize(); // final zona MPI
	
	return 0;
}
