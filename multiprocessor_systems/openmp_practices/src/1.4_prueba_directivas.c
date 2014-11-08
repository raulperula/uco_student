/**
 * @file    1.4_prueba_directivas.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

#include <stdio.h>
#include <time.h>
#include <omp.h>

int valor;
#pragma omp threadprivate(valor)

int main(int argc, char** argv)
{
	omp_set_num_threads(4);
	
	int n = omp_get_max_threads(), i, j, tid, suma = 0;
	int v[n];
	
	// directiva single
	printf("\nDirectiva Single\n");
	#pragma omp parallel
	{
		// si esta dentro de la directiva se ejecuta como si fuese secuencial, es decir, solo hay un hilo
		#pragma omp single
		printf("Hilo %d de %d (dentro)\n", omp_get_thread_num(), omp_get_num_threads());
		
		// fuera de la directiva se ejecuta en cada uno de los hilos
		printf("Hilo %d de %d (fuera)\n", omp_get_thread_num(), omp_get_num_threads());
	}
	
	// directiva barrier
	printf("\nDirectiva Barrier\n");
	#pragma omp parallel
	{
		int tid = omp_get_thread_num();
		
		sleep(tid);
		printf("mensaje hilo %d\n", tid);
		
		#pragma omp barrier
		printf("mensaje comun\n");
	}
	
	// directiva master
	printf("\nDirectiva Master\n");
	#pragma omp parallel
	{
		// si esta dentro de la directiva se ejecuta como si fuese el hilo principal, el hilo 0
		#pragma omp master
		printf("Hilo %d de %d (dentro)\n", omp_get_thread_num(), omp_get_num_threads());
		
		// fuera de la directiva se ejecuta en cada uno de los hilos
		printf("Hilo %d de %d (fuera)\n", omp_get_thread_num(), omp_get_num_threads());
	}
	
	// directiva critical
	printf("\nDirectiva Critical\n");
	#pragma omp parallel
	{
		int tid = omp_get_thread_num();
		
		sleep(tid);
		printf("mensaje hilo %d\n", tid);
		
		#pragma omp critical
		printf("mensaje comun\n");
	}
	
	// directiva ordered
	printf("\nDirectiva Ordered\n");
	
	v[0] = v[1] = 1;
	
	#pragma omp parallel for ordered shared(v,i,j)
	for(i=0;i<n;i++){
		for(j=2;j<i;j++){
			v[j] += v[i];
		}
		printf("H(%d)\n", omp_get_thread_num());
	}
	
	for(i=0;i<n;i++){
		printf("v = %d\n", v[i]);
	}
	
	// directiva flush
	printf("\nDirectiva Flush\n");

	for(i=0;i<n;i++){
		v[i] = 1;
	}
	
	#pragma omp parallel shared(v)
	{
		tid = omp_get_thread_num();
		
		for(i=0;i<100000;i++){
			v[tid]++;
			
			if((tid == 0) && (v[0]%100 == 0)){
				v[tid]++;
				#pragma omp flush (v)
			}
			if(v[0]%100 == 0){
				if(tid != 0){
					printf("Valor anterior = %d\n", v[0]);
					#pragma omp flush (v)
					printf("Valor real = %d\n", v[0]);
				}
			}
		}
	}
	
	// directiva threadprivate
	printf("\nDirectiva Threadprivate\n");
	
	int valor1;
	
	/*Primera región paralela*/
	printf("Primera region\n");
	#pragma omp parallel
	{
		valor = omp_get_thread_num();
		valor1 = valor;
		
		tid = omp_get_thread_num();
		
		printf("Hilo %d: valor: %d\n", tid, valor);
		printf("Hilo %d: valor1: %d\n", tid, valor1);
	}
	
	/*Segunda región paralela*/
	printf("\nSegunda region\n");
	#pragma omp parallel
	{
		tid = omp_get_thread_num();
		
		printf("Hilo %d: valor: %d\n", tid, valor);
		printf("Hilo %d: valor1: %d\n", tid, valor1);
	}
	
	return 0;
}
