/**
 * @file    practica1_2e.c
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
	int myrank, size, sum = 0, num;
	MPI_Status estado;
	
	MPI_Init(&argc, &argv); // comienzo zona MPI
	
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank); // id del proceso
	MPI_Comm_size(MPI_COMM_WORLD, &size); // numero de procesos
	
	num = myrank;
	
	if(myrank == 0){
		MPI_Reduce(&num, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
		printf("Suma: %d\n", sum);
	}
	else{
		MPI_Reduce(&num, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	}
	
	MPI_Finalize(); // final zona MPI
	
	return 0;
}
