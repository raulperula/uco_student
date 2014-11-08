/**
 * @file    practica1_2d.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

#include <stdio.h>
#include <strings.h>
#include <mpi.h>

#define N 50

int main(int argc, char** argv)
{
	int myrank, size;
	char cad1[N], cad2[N];
	MPI_Status estado;
	
	MPI_Init(&argc, &argv); // comienzo zona MPI
	
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank); // id del proceso
	MPI_Comm_size(MPI_COMM_WORLD, &size); // numero de procesos
	
	sprintf(cad1, "Hola mundo!!\n", myrank);
	
	if(myrank == 0){
		bzero(cad2, sizeof(cad2));
		MPI_Scatter(cad1, 2, MPI_CHAR, cad2, 2, MPI_CHAR, 0, MPI_COMM_WORLD);
		printf("Padre %d: %s\n", myrank, cad2);
	}
	else{
		bzero(cad2, sizeof(cad2));
		MPI_Scatter(cad1, 2, MPI_CHAR, cad2, 2, MPI_CHAR, 0, MPI_COMM_WORLD);
		printf("Hijo %d: %s\n", myrank, cad2);
	}
	
	MPI_Finalize(); // final zona MPI
	
	return 0;
}
