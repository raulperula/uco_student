/**
 * @file    1.2_hola_mundo.c
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

int main(int argc, char** argv)
{
	double tiempo_inicio;
	
	omp_set_num_threads(2);
	
	tiempo_inicio = omp_get_wtime();
	printf("Tiempo inicio: %f\n", tiempo_inicio);

	printf("\nProcesadores disponibles: %d\n", omp_get_num_procs());
	printf("\nNumero de hilos (num_threads): %d\nNumero de hilos (max_threads): %d\n\n", omp_get_num_threads(), omp_get_max_threads());
	
	printf("\nEs paralelo? %s\n\n", (omp_in_parallel() == 1) ? "true" : "false");
	
	#pragma omp parallel
	{
		printf("Hilo %d: Hola mundo\n", omp_get_thread_num());
		//~ printf("\nNumero de hilos (num_threads): %d\nNumero de hilos (max_threads): %d\n\n", omp_get_num_threads(), omp_get_max_threads());
		//~ printf("Tiempo: %f\n", omp_get_wtime());
		//~ printf("\nEs paralelo? %s\n\n", (omp_in_parallel() == 1) ? "true" : "false");
	}
	
	printf("\nTiempo fin: %f\n", omp_get_wtime());
	printf("\nTiempo total: %f\n", omp_get_wtime()-tiempo_inicio);
	
	return 0;
}
