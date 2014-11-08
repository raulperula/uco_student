/**
 * @file    practica2_2.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc,char*argv[])
{
	// Se estaban enviando datos de tipo int y se estaban recibiendo de tipo
	// float, tienen que ser del mismo tipo, por ejemplo, int ambos
	int numtasks, rank, tag=1, alpha, i, beta;
	//float beta; No puede ser de tipo float
	
	MPI_Request reqs[10];
	MPI_Status stats[10];

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	if(rank == 0)
	{
		if(numtasks > 2)
			printf("Numtasks=%d.   Only   2   needed.   Ignoring extra...\n",numtasks);
			
		for(i=0; i<10; i++){
			alpha = i*10;
			MPI_Isend(&alpha,1, MPI_INT,1, tag, MPI_COMM_WORLD,&reqs[i]);
			MPI_Wait(&reqs[i],&stats[i]);
			printf("Task %d sent = %d\n",rank,alpha);
		}
	}

	if(rank == 1)
	{
		for(i=0; i<10; i++){
			// El tipo ahora no puede ser de tipo float, sino int (MPI_INT)
			MPI_Irecv(&beta,1, MPI_INT,0, tag, MPI_COMM_WORLD,&reqs[i]);
			MPI_Wait(&reqs[i],&stats[i]);
			printf("Task %d received = %d\n",rank,beta);
		}
	}
	
	MPI_Finalize();
}
