/**
 * @file    codigo.c
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

float A[8192][8192], B[8192][8192+8];

int
main()
{
	int i, j;
	
	for(i=0;i<4000;i++){
		for(j=0;j<4000;j++){
			B[i][j] = 0;
		}
	}

	for(i=0;i<4000;i++){
		for(j=0;j<4000;j++){
			A[i][j] = B[j][i];
		}
	}
}
