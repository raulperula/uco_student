/**
 * @file    practica1_2a.c
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

int main(int argc, char** argv)
{
	int myrank, size;
	
	MPI_Init(&argc, &argv); // comienzo zona MPI
	
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank); // id del proceso
	MPI_Comm_size(MPI_COMM_WORLD, &size); // numero de procesos
	
	printf("Hola mundo -> proceso %d de %d\n", myrank, size);
	
	MPI_Finalize(); // final zona MPI
	
	return 0;
}
