/**
 * @file    codigoNT.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
// Cache L1: C = 64, W = 8
// Cache L2: C = 4092, W = 8

#include <stdio.h>
#include <math.h>

float A[2000][2000], B[2000][2000], C[2000][2000];

int
main()
{
	int i, j, k;
	
	for(i=0;i<2000;i++){
		for(j=0;j<2000;j++){
			B[i][j] = 1;
			C[i][j] = 1;
		}
	}

	for(i=0;i<2000;i+=1){
		for(k=0;k<2000;k+=1){
			for(j=0;j<2000;j+=1){
				A[i][j] += B[i][k]*C[k][j];
			}
		}
	}
}
