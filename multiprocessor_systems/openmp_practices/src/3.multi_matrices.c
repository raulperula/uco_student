/**
 * @file    3.multi_matrices.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <omp.h>

#define X 800
#define Y 800
#define Z 800

int main(int argc, char** argv)
{
	int A[X][Y], B[Y][Z], C[X][Z];
	int i, j, k;
	double t;
	
	// inicializacion semilla
	srand(time(NULL));
	
	// inicializacion de las matrices
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){
			A[i][j] = rand()%10;
			B[i][j] = rand()%10;
		}
	}
	
	// multiplicacion secuencial
	t = clock();
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){
			for(k=0;k<Z;k++){
				C[i][j] += A[i][k]+B[k][j];
			}
		}
	}
	printf("\nT. total (secuencial): %f seg\n", (clock()-t)/CLOCKS_PER_SEC);
	
	// imprimir el resultado
	printf("\n");
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){
			//~ printf("%d ", C[i][j]);
		}
		//~ printf("\n");
	}
	
	// multiplicacion openmp
	t = clock();
	#pragma omp parallel for private(i,j,k) shared(C)
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){
			for(k=0;k<Z;k++){
				C[i][j] += A[i][k]+B[k][j];
			}
		}
	}
	printf("\nT. total (paralelo): %f seg\n", (clock()-t)/CLOCKS_PER_SEC);
	
	// imprimir el resultado
	printf("\n");
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){
			//~ printf("%d ", C[i][j]);
		}
		//~ printf("\n");
	}
	
	return 0;
}
