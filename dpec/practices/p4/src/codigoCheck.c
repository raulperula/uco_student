/**
 * @file    codigoCheck.c
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

float A[2000][2000], AA[2000][2000], B[2000][2000], C[2000][2000];

void printDiff(float data1[2000][2000], float data2[2000][2000], int width, int height, int iListLength, float fListTol)
{
    printf("Listing first %d.", iListLength);
    printf(" Differences > %.6f...\n", fListTol);
    int i, j;
    int error_count = 0;
    for(j=0;j<height;j++){
        for(i=0;i<width;i++){
            float fDiff = fabs(data1[i][j]-data2[i][j]);
            if(fDiff>fListTol){
                if(error_count < iListLength){
                    printf("    Loc(%d,%d)\tCPU=%.5f\tGPU=%.5f\tDiff=%.6f\n", i, j, data1[i][j], data2[i][j], fDiff);
                }
                error_count++;
            }
        }
    }
    printf(" \n  Total Errors = %d of %d\n\n", error_count, 2000*2000);
}

int
main()
{
	int i, j, k, ii, jj, kk;
	int TTI, TTJ, TTK;
	int mini, minj, mink;
	
	TTI = 2000/8;
	TTJ = 64/2;
	TTK = 64/(2*2);
	
	for(i=0;i<2000;i++){
		for(j=0;j<2000;j++){
			B[i][j] = 1;
		}
	}
	
	for(i=0;i<2000;i++){
		for(j=0;j<2000;j++){
			C[i][j] = 1;
		}
	}
	
	// codigo no tiling
	
	for(i=0;i<2000;i+=1){
		for(k=0;k<2000;k+=1){
			for(j=0;j<2000;j+=1){
				A[i][j] += B[i][k]*C[k][j];
			}
		}
	}
	
	// codigo tiling
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
							AA[i][j] += B[i][k]*C[k][j];
						}
					}
				}
			}
		}
	}
	
	printDiff(A, AA, 2000, 2000, 100, 1.0e-3f);
}
