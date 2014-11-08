/**
 * @file    omp_bug1.c
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

#define N 50
#define CHUNKSIZE 5

int main (int argc, char *argv[])
{
	int i, chunk, tid;
	float a[N], b[N], c[N];
	
	/* Some initializations */
	for (i=0; i < N; i++){
		a[i] = b[i] = i * 1.0;
	}
	
	chunk = CHUNKSIZE;
	
	#pragma omp parallel	 	\
	shared(a,b,c,chunk) 		\
	private(i,tid)
	{
		tid = omp_get_thread_num();
		
		#pragma omp parallel for schedule(static,chunk)
		for (i=0; i < N; i++){
			c[i] = a[i] + b[i];
			printf("tid= %d i= %d c[i]= %f\n", tid, i, c[i]);
		}
	} /* end of parallel for construct */
	
	//~ el error estaria en que el bloque no podria tener un parallel for directamente ya que
	//~ hay mas codigo contenido a parte del for, al cambiar esto, la opcion schedule habria
	//~ que traspasarla al parallel for de abajo para que funcione
}
