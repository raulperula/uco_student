/**
 * @file    matrizCuda.cu
 * @brief   CUDA program.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <iostream>

#define TILE_WIDTH 4
using namespace std;

__global__ void d_procesarMatriz(int * d_a, int * d_b, int * d_c, int width);
void checkCUDAError(const char *msg);   // funcion para comprobar los errores de CUDA

int main(int argc, char** argv)
{
    // se crean los punteros de las matrices origen
    int * h_a, * h_b, * h_c;

    // se crean los punteros de las matrices destino
    int * d_a, * d_b, * d_c;

    // se define la rejilla y el tamaño de bloque
    int numBlocks = 4;
    int numThreadsPerBlock = 16;

    // Parte 1 de 5: reservar memoria principal y en GPU
    size_t memSize = sizeof(int)*numBlocks*numThreadsPerBlock;

    h_a = (int *) malloc(memSize);
    cudaMalloc((void**) &d_a,memSize );

    h_b = (int *) malloc(memSize);
    cudaMalloc((void**) &d_b,memSize );

    h_c = (int *) malloc(memSize);
    cudaMalloc((void**) &d_c,memSize );

    for(int n=0;n<numThreadsPerBlock*numBlocks;n++){
        h_a[n] = h_b[n] = 1;
    }

    // Part 2 of 5: configure and launch kernel
    dim3 dimGrid(numBlocks/2, numBlocks/2 );
    dim3 dimBlock(numThreadsPerBlock/TILE_WIDTH, numThreadsPerBlock/TILE_WIDTH);

    // check if kernel execution generated an error
    checkCUDAError("kernel execution");

    // Part 4 of 5: device to host copy
    cudaMemcpy(d_a, h_a, memSize, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, memSize, cudaMemcpyHostToDevice);

    MatrixTiles<<< dimGrid ,dimBlock  >>>(d_a,d_b,d_c,TILE_WIDTH*2);

    // block until the device has completed
    cudaThreadSynchronize();
    cudaMemcpy(h_c, d_c, memSize, cudaMemcpyDeviceToHost);

    // Check for any CUDA errors
    checkCUDAError("cudaMemcpy");

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)
            cout<<h_c[8*i+j]<<" ";
        cout<<endl;
    }

    // free device memory
    cudaFree(d_a);

    // free host memory
    free(h_a);

    // If the program makes it this far, then the results are correct and
    // there are no run-time errors.  Good work!
    printf("Correct!\n");

    return 0;
}

// kernel que se ejecuta en paralelo en múltiples tareas para una matriz
__global__ void d_procesarMatriz(int * d_a, int * d_b,int * d_c, int width)
{
    int row = blockIdx.x*TILE_WIDTH+threadIdx.x;
    int col = blockIdx.y*TILE_WIDTH+threadIdx.y;

    int pvalue = 0;

    // se calcula para cada uno de los elementos de la submatriz
    for(int i=0;i<width;i++){
        pvalue += (d_a[row*width+i]*d_b[i*width+col]);
    }

    d_c[row*width+col] = pvalue;
}

void checkCUDAError(const char *msg)
{
    cudaError_t err = cudaGetLastError();
    if(cudaSuccess != err){
        cerr<<"Cuda error: "<<msg<<": "<<cudaGetErrorString(err)<<endl;
        exit(-1);
    }
}
