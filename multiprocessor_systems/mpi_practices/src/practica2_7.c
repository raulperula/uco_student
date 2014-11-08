/**
 * @file    practica2_7.c
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
	int numtasks, taskid, len, buffer, root, count;
	char hostname[MPI_MAX_PROCESSOR_NAME];

	MPI_Init(&argc,&argv);
	
	MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD,&taskid);
	MPI_Get_processor_name(hostname,&len);

	printf ("Task %d on %s starting...\n", taskid, hostname);

	buffer = 23;
	root = 0;

	// Para poder enviar los datos, la variable "count" no puede valer cero, 
	// como lo hace al estar igualada a taskid, para enviar los datos se podria 
	// igualar a uno
	count = 1;
	//count = taskid;

	if(taskid == root)
	   printf("Root: Number of MPI tasks is: %d \n", numtasks);

	MPI_Bcast(&buffer, count, MPI_INT, root, MPI_COMM_WORLD);
	
	MPI_Finalize();
}
