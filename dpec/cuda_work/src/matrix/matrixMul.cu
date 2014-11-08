/**
 * @file    matrixMul.cu
 * @brief   CUDA program.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include "cutil_inline.h"

// includes, kernels
#include <matrixMul_kernel.cu>

void printDiff(float *data1, float *data2, int width, int height, int iListLength, float fListTol)
{
    printf("Listing first %d Differences > %.6f...\n", iListLength, fListTol);
    int i,j,k;
    int error_count=0;
    for (j = 0; j < height; j++) {
        if (error_count < iListLength) {
            //~ printf("\n  Row %d:\n", j);
        }
        for (i = 0; i < width; i++) {
            k = j * width + i;
            float fDiff = fabs(data1[k] - data2[k]);
            if (fDiff > fListTol) {
                if (error_count < iListLength) {
                    printf("    Loc(%d,%d)\tCPU=%.5f\tGPU=%.5f\tDiff=%.6f\n", i, j, data1[k], data2[k], fDiff);
                }
                error_count++;
            }
        }
    }
    printf(" \n  Total Errors = %d\n\n", error_count);
}

void computeGold(float* C, const float* A, const float* B, unsigned int hA, unsigned int wA, unsigned int wB)
{
    for (unsigned int i = 0; i < hA; ++i)
        for (unsigned int j = 0; j < wB; ++j) {
            double sum = 0;
            for (unsigned int k = 0; k < wA; ++k) {
                double a = A[i * wA + k];
                double b = B[k * wB + j];
                sum += a * b;
            }
            C[i * wB + j] = (float)sum;
        }
}

// Allocates a matrix with random float entries.
void randomInit(float* data, int size)
{
    for (int i = 0; i < size; ++i)
        data[i] = rand() / (float)RAND_MAX;
}

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
    // set seed for rand()
    srand(2006);

    // allocate host memory for matrices A and B
    unsigned int size_A = WA * HA;
    unsigned int mem_size_A = sizeof(float) * size_A;

    float* h_A = (float*)malloc(mem_size_A);

    unsigned int size_B = WB * HB;
    unsigned int mem_size_B = sizeof(float) * size_B;

    float* h_B = (float*)malloc(mem_size_B);

    // initialize host memory
    randomInit(h_A, size_A);
    randomInit(h_B, size_B);

    // print out matrix A and B
    //~ for(int i = 0; i < size_A; i++) {
       //~ printf("%f ", h_A[i]);
       //~ if(((i + 1) % WA) == 0)
          //~ printf("\n");
    //~ }
 //~
    //~ printf("\n\nMatrix B\n");
    //~ for(int i = 0; i < size_B; i++) {
       //~ printf("%f ", h_B[i]);
       //~ if(((i + 1) % WB) == 0)
          //~ printf("\n");
    //~ }

    // allocate device memory
    float* d_A;
    cutilSafeCall(cudaMalloc((void**) &d_A, mem_size_A));

    float* d_B;
    cutilSafeCall(cudaMalloc((void**) &d_B, mem_size_B));

    // copy host memory to device
    cutilSafeCall(cudaMemcpy(d_A, h_A, mem_size_A,cudaMemcpyHostToDevice));
    cutilSafeCall(cudaMemcpy(d_B, h_B, mem_size_B,cudaMemcpyHostToDevice));

    // allocate device memory for result
    unsigned int size_C = WC * HC;
    unsigned int mem_size_C = sizeof(float) * size_C;

    float* d_C;
    cutilSafeCall(cudaMalloc((void**) &d_C, mem_size_C));

    // allocate host memory for the result
    float* h_C = (float*) malloc(mem_size_C);

    // setup execution parameters
    dim3 threads(BLOCK_SIZE, BLOCK_SIZE);
    dim3 grid(WC / threads.x, HC / threads.y);

    // kernel warmup
    //~ matrixMul<<< grid, threads >>>(d_C, d_A, d_B, uiWA, uiWB);
    //~ cudaThreadSynchronize();

    // create and start timer
    unsigned int timer = 0;
    cutilCheckError(cutCreateTimer(&timer));
    cutilCheckError(cutStartTimer(timer));

    // execute the kernel
    matrixMul<<< grid, threads >>>(d_C, d_A, d_B, WA, WB);

    cudaThreadSynchronize();

    // stop and destroy timer
    cutilCheckError(cutStopTimer(timer));
    double dSeconds = cutGetTimerValue(timer)/(1000.0);
    double dNumOps = 2.0 * (double) WA * (double) HA * (double) WB;
    double gflops = 1.0e-9 * dNumOps/dSeconds;

    //Log througput, etc
    printf("matrixMul, Throughput = %.4f GFlop/s, Time = %.5f s, Size = %.0f Ops, NumDevsUsed = %d, Workgroup = %u\n",
        gflops, dSeconds, dNumOps, 1, threads.x * threads.y);
    cutilCheckError(cutDeleteTimer(timer));

    // copy result from device to host
    cutilSafeCall(cudaMemcpy(h_C, d_C, mem_size_C,cudaMemcpyDeviceToHost));

    // print out the results
    //~ printf("\n\nMatrix C (Results)\n");
    //~ for(int i = 0; i < size_C; i++) {
       //~ printf("%f ", h_C[i]);
       //~ if(((i + 1) % WC) == 0)
          //~ printf("\n");
    //~ }
    //~ printf("\n");

    //~ // compute reference solution
    float* reference = (float*)malloc(mem_size_C);
    computeGold(reference, h_A, h_B, HA, WA, WB);

    // check result
    printDiff(reference, h_C, WC, HC, 100, 1.0e-4f);

    // clean up memory
    free(h_A);
    free(h_B);
    free(h_C);
    free(reference);
    cutilSafeCall(cudaFree(d_A));
    cutilSafeCall(cudaFree(d_B));
    cutilSafeCall(cudaFree(d_C));

    cudaThreadExit();
}
