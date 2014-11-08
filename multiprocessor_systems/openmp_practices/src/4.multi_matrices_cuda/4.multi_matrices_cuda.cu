/**
 * @file    4.multi_matrices_cuda.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <omp.h>
#include "cutil_inline.h"

// includes, kernels
#include <matrixMul_kernel.cu>

#define F 2000
#define C 2000

void printDiff(float * data1, float * data2, int width, int height, int iListLength, float fListTol)
{
    printf("Listing first %d with error.", iListLength);
    printf(" Differences > %.6f...\n", fListTol);
    int i, j, k;
    int error_count = 0;
    for(j=0;j<height;j++){
        for(i=0;i<width;i++){
            k = j*width+i;
            float fDiff = fabs(data1[k]-data2[k]);
            if(fDiff>fListTol){
                if(error_count < iListLength){
                    printf("    Loc(%d,%d)\tCPU=%.5f\tGPU=%.5f\tDiff=%.6f\n", i, j, data1[k], data2[k], fDiff);
                }
                error_count++;
            }
        }
    }
    printf(" \n  Total Errors = %d of %d\n\n", error_count, WA*HA);
}

// matrix multiplication in cpu
void matrixMulHOMP(float * C, const float * A, const float * B, unsigned int hA, unsigned int wA, unsigned int wB)
{
	#pragma omp parallel for shared(C,suma,i,j,k)
	for(unsigned int i=0;i<hA;++i){
		for(unsigned int j=0;j<wB;++j){
			double sum = 0;
			for(unsigned int k=0;k<wA;++k){
				sum += A[i*wA+k]*B[k*wB+j];
			}
			C[i*wB+j] = (float) sum;
		}
	}
}
void matrixMulH(float * C, const float * A, const float * B, unsigned int hA, unsigned int wA, unsigned int wB)
{
	for(unsigned int i=0;i<hA;++i){
		for(unsigned int j=0;j<wB;++j){
			double sum = 0;
			for(unsigned int k=0;k<wA;++k){
				sum += A[i*wA+k]*B[k*wB+j];
			}
			C[i*wB+j] = (float) sum;
		}
	}
}

// Allocates a matrix with random float entries.
void randomInit(float * data, int size)
{
    for(long int i=0;i<size;++i){
		data[i] = rand()/(float)RAND_MAX;
	}
}

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char ** argv)
{
    unsigned int size_B, mem_size_B, cmem_size_B;

    // set seed for rand()
    srand(1988);

    // allocate host memory for matrices A and B
    // check if padding is active (option == 1)
    unsigned int size_A = WA*HA;
	unsigned int mem_size_A = sizeof(float)*size_A;

	float * h_A = (float *) malloc(mem_size_A);

	size_B = WB*HB;
	mem_size_B = sizeof(float)*size_B;

	float * h_B = (float *) malloc(mem_size_B);

	//~ printf("\nA size: %dx%d\n", WA, HA);
	//~ printf("B size: %dx%d\n", WB, HB);

    // initialize host memory
    randomInit(h_A, size_A);
    randomInit(h_B, size_B);

    // allocate device memory
    float * d_A;
    cutilSafeCall(cudaMalloc((void **) &d_A, mem_size_A));

	float * d_B;
	cutilSafeCall(cudaMalloc((void **) &d_B, mem_size_B));

    // copy host memory to device
    cutilSafeCall(cudaMemcpy(d_A, h_A, mem_size_A,cudaMemcpyHostToDevice));
	cutilSafeCall(cudaMemcpy(d_B, h_B, mem_size_B,cudaMemcpyHostToDevice));

    // allocate device memory for result
    unsigned int size_C = WC*HC;
    unsigned int mem_size_C = sizeof(float)*size_C;

    float * d_C;
    cutilSafeCall(cudaMalloc((void **) &d_C, mem_size_C));

    // allocate host memory for the result
    float * h_C = (float*) malloc(mem_size_C);

    // setup execution parameters
    dim3 threads(BLOCK_SIZE, BLOCK_SIZE);  // threads/block
    dim3 grid(WC/threads.x+((WC%BLOCK_SIZE == 0)?0:1), HC/threads.y+((HC%BLOCK_SIZE == 0)?0:1)); // total blocks
    
    // create and start timer
    unsigned int timer = 0;
    cutilCheckError(cutCreateTimer(&timer));
    cutilCheckError(cutStartTimer(timer));

	///////////////////////////////
    // execute the kernel
    ///////////////////////////////
	matrixMulD<<< grid, threads >>>(d_C, d_A, d_B, WA, WB);

    cudaThreadSynchronize();

    // stop and destroy timer
    cutilCheckError(cutStopTimer(timer));
    double dSeconds = cutGetTimerValue(timer)/(1000.0);
    cutilCheckError(cutDeleteTimer(timer));

	printf("\nDevice time\t= %.8f s\n", dSeconds);

    // copy result from device to host
    cutilSafeCall(cudaMemcpy(h_C, d_C, mem_size_C,cudaMemcpyDeviceToHost));

    // compute reference solution
    float * hc_C = (float *) malloc(mem_size_C);

	///////////////////////////////
    // execute host multiplication
    ///////////////////////////////
    unsigned int timerH = 0;
    cutilCheckError(cutCreateTimer(&timerH));
    cutilCheckError(cutStartTimer(timerH));

	// secuential multiplication
	matrixMulH(hc_C, h_A, h_B, HA, WA, WB);

    cutilCheckError(cutStopTimer(timerH));
    double hSeconds = cutGetTimerValue(timerH)/(1000.0);
	cutilCheckError(cutDeleteTimer(timerH));
	
	printf("\nHost time\t= %.8f s\n", hSeconds);

    // check result
	//~ printDiff(hc_C, h_C, WC, HC, 100, 1.0e-2f);
	
	///////////////////////////////
    // execute OPM multiplication
    ///////////////////////////////
    double t_inicio;
    t_inicio = omp_get_wtime();
    
    // OPM multiplication
	matrixMulHOMP(hc_C, h_A, h_B, HA, WA, WB);
	
	printf("\nOMP time\t= %.8f s\n", omp_get_wtime()-t_inicio);

    // clean up memory
    free(h_A);
    free(h_B);
    free(h_C);
    free(hc_C);
    cutilSafeCall(cudaFree(d_A));
    cutilSafeCall(cudaFree(d_B));
    cutilSafeCall(cudaFree(d_C));

    cudaThreadExit();
}
