/**
 * @file    codigoPermutado.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>

float A[1024][1024], B[1024][1024];

int
main()
{
	int i, j;
	
	for(i=0;i<1024;i++){
		for(j=0;j<1024;j++){
			B[i][j] = 0;
		}
	}

	for(j=0;j<600;j++){
		for(i=0;i<600;i++){
			A[i][j] = B[i][j];
		}
	}
}
