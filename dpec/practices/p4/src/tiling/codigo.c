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
#include <math.h>

#define MIN(a,b) (a < b) ? (a) : (b)

float A[2000][2000], B[2000][2000], C[2000][2000];

int
main()
{
	int i, j, k, ii, jj, kk;
	int TTI, TTJ, TTK;
	int mini, minj, mink;
	
	// i -> num. iter. / W
	// j -> C(L1) / beta
	// k -> C(L1) / beta * num. apariciones
	
	TTI = 2000/8;
	TTJ = 64/2;
	TTK = 64/(2*2);
	
	for(i=0;i<2000;i++){
		for(j=0;j<2000;j++){
			B[i][j] = 1;
			C[i][j] = 1;
		}
	}

	for(ii=0;ii<2000;ii+=TTI){
		for(kk=0;kk<2000;kk+=TTK){
			for(jj=0;jj<2000;jj+=TTJ){
				mini = MIN(ii+TTI,2000);
				for(i=ii;i<mini;i++){
					mink = MIN(kk+TTK,2000);
					for(k=kk;k<mink;k++){
						minj = MIN(jj+TTJ,2000);
						for(j=jj;j<minj;j++){
							// indice mas externo se encuentra en la dimension contigua
							A[i][j] += B[i][k]*C[k][j];
						}
					}
				}
			}
		}
	}
}
