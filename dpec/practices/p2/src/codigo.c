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
 
#include <stdio.h>

float A[2200][2200], B[2200][2200];

int
main()
{
	int i, j;
	
	for(i=0;i<2200;i++){
		for(j=0;j<2200;j++){
			B[i][j] = 0;
		}
	}

	for(i=0;i<2000;i++){
		for(j=0;j<2000;j++){
			A[i][j] = B[i][j];
		}
	}
}
