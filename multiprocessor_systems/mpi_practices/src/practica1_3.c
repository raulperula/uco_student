/**
 * @file    practica1_3.c
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

#define N 1200
#define M 200

int main(int argc, char** argv)
{
	int myrank, size, i;
	int v[N], v_aux[M];
	int sum = 0, total = 0;
	MPI_Status estado;
	
	MPI_Init(&argc, &argv); // comienzo zona MPI
	
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank); // id del proceso
	MPI_Comm_size(MPI_COMM_WORLD, &size); // numero de procesos
	
	for(i=0;i<N;i++){
		v[i] = i;
	}
	
	if(myrank == 0){
		MPI_Scatter(v, M, MPI_INT, v_aux, M, MPI_INT, 0, MPI_COMM_WORLD);
		sum = 0;
		for(i=0;i<M;i++){
			sum += v_aux[i];
		}
		MPI_Reduce(&sum, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
		printf("Suma : %d\n", total);
	}
	else{
		sum = 0;
		MPI_Scatter(v, M, MPI_INT, v_aux, M, MPI_INT, 0, MPI_COMM_WORLD);
		for(i=0;i<M;i++){
			sum += v_aux[i];
		}
		MPI_Reduce(&sum, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	}
	
	MPI_Finalize(); // final zona MPI
	
	return 0;
}
