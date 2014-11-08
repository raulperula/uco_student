/**
 * @file    matrizCuda1.cu
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

using namespace std;

// Simple utility function to check for CUDA runtime errors
void checkCUDAError(const char *msg);

// Part 3 of 5: implement the kernel
__global__ void MatrixSimple(int *d_a ,int *d_b,int *d_c,int width )
{
    int row = blockIdx.x*width+threadIdx.x;
    int col = blockIdx.y*width+threadIdx.y;

    //for each computes one element of the block sub-matrix
    for(int i=0;i<width;i++){
        d_c[row*width+col] = d_a[row*width+i]+d_b[i*width+col];
    }
}

int main( int argc, char** argv)
{
    // pointer for host memory
    int * h_a, * h_b, * h_c;

    // pointer for device memory
    int * d_a, * d_b, * d_c;

    // define grid and block size
    int numBlocks = 1;
    int numThreadsPerBlock = 64;

    // Part 1 of 5: allocate host and device memory
    size_t memSize = numBlocks*numThreadsPerBlock*sizeof(int);

    h_a = (int *) malloc(memSize);
    if(cudaMalloc((void**) &d_a,memSize) != cudaSuccess){
        cout<<"ERROR cudaMalloc"<<endl;
        exit(-1);
    }
    h_b = (int *) malloc(memSize);
    cudaMalloc((void**) &d_b,memSize);
    h_c = (int *) malloc(memSize);
    cudaMalloc((void**) &d_c,memSize);

    for(int n=0;n<numThreadsPerBlock*numBlocks;n++){
        h_a[n] = h_b[n] = 1;
        h_c[n] = 0;
    }

    // Part 2 of 5: configure and launch kernel
    dim3 dimGrid(numBlocks);
    dim3 dimBlock(numThreadsPerBlock/8, numThreadsPerBlock/8);

    // check if kernel execution generated an error
    //~ checkCUDAError("kernel execution");

    // Part 4 of 5: device to host copy
    cudaMemcpy(d_a, h_a, memSize, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, memSize, cudaMemcpyHostToDevice);

    MatrixSimple <<< dimGrid,dimBlock >>>(d_a, d_b, d_c, numThreadsPerBlock/8);

    // block until the device has completed
    cudaThreadSynchronize();
    cudaMemcpy(h_c, d_c, memSize, cudaMemcpyDeviceToHost);

    // Check for any CUDA errors
    //~ checkCUDAError("cudaMemcpy");

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)
            cout<<h_c[8*i+j]<<"\t";
        cout<<endl;
    }

    // free device memory
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    // free host memory
    free(h_a);
    free(h_b);
    free(h_c);

    // If the program makes it this far, then the results are correct and
    // there are no run-time errors. Good work!
    printf("Correct!\n");

    return 0;
}

void checkCUDAError(const char *msg)
{
    cudaError_t err = cudaGetLastError();
    if( cudaSuccess != err)
    {
        fprintf(stderr, "Cuda error: %s: %s.\n", msg, cudaGetErrorString( err) );
        exit(-1);
    }
}
