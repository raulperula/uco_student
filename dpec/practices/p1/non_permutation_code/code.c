/**
 * @file    code.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>

float A[2000][2000], B[2000][2000];

int
main()
{
	int i, j;
	
	for(i=0;i<2000;i++){
		for(j=0;j<2000;j++){
			A[i][j] = 0;
		}
	}

	for(i=0;i<1600;i++){
		for(j=0;j<1600;j++){
			A[i][j] = B[i][j];
		}
	}
}
