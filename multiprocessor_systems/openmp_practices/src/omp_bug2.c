/**
 * @file    omp_bug2.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	int nthreads, i, tid;
	float total;
	
	/*** Spawn parallel region ***/
	//~ habria que añadir el private(tid) para que el tid sea correcto en todo momento
	#pragma omp parallel private(tid) shared(total)
	{
		/* Obtain thread number */
		tid = omp_get_thread_num();
		
		/* Only master thread does this */
		if (tid == 0) {
			nthreads = omp_get_num_threads();
			printf("Number of threads = %d\n", nthreads);
		}
		
		printf("Thread %d is starting...\n",tid);
		
		total = 0.0;
		#pragma omp barrier
		
		/* do some work */
		#pragma omp for schedule(dynamic,10)
		for (i=0; i<10; i++)
			total = total + i*1.0;

		printf ("Thread %d is done! Total= %f\n",tid,total);
	} /*** End of parallel region ***/
}
