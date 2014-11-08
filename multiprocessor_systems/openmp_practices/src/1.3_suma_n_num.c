/**
 * @file    1.3_suma_n_num.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

#include <stdio.h>
#include <omp.h>

#define N 5

int main(int argc, char** argv)
{
	int v[N], i, suma;
	
	for(i=0;i<N;i++){
		v[i] = i;
	}
	
	omp_set_num_threads(4);

	printf("Private\n");
	#pragma omp parallel private(suma)
	{
		suma = 0;
		
		for(i=0;i<N;i++){
			suma += v[i];
		}
		
		printf("Hilo %d. Suma %d\n", omp_get_thread_num(), suma);
	}
	
	printf("\nShared\n");
	#pragma omp parallel shared(suma)
	{
		for(i=0;i<N;i++){
			suma += v[i];
		}
		
		printf("Hilo %d. Suma %d\n", omp_get_thread_num(), suma);
	}
	
	printf("\nIf\n");
	// si la condicion se cumple ejecuta el codigo paralelamente
	// si no la cumple, ejecuta el codigo una vez secuencialmente
	#pragma omp parallel if(suma < 10)
	{
		for(i=0;i<N;i++){
			suma += v[i];
		}
		
		printf("Hilo %d. Suma %d\n", omp_get_thread_num(), suma);
	}
	
	printf("\nFirstprivate\n");
	#pragma omp parallel firstprivate(suma)
	{
		for(i=0;i<N;i++){
			suma += v[i];
		}
		
		printf("Hilo %d. Suma %d\n", omp_get_thread_num(), suma);
	}
	
	printf("\nParallel reduction\n");
	#pragma omp parallel
	{
		#pragma omp for reduction(+:suma)
		for(i=0;i<N;i++){
			suma += v[i];
		}
		printf("Hilo %d. Suma %d\n", omp_get_thread_num(), suma);
	}
	
	printf("\nParallel for con nowait\n");
	#pragma omp parallel shared(suma)
	{
		#pragma omp for nowait
		for(i=0;i<N;i++){
			suma += v[i];
		}
		printf("Hilo %d. Suma %d\n", omp_get_thread_num(), suma);
	}
	printf("\nParallel for sin nowait\n");
	#pragma omp parallel shared(suma)
	{
		#pragma omp for
		for(i=0;i<N;i++){
			suma += v[i];
		}
		
		printf("Hilo %d. Suma %d\n", omp_get_thread_num(), suma);
	}
	
	return 0;
}
