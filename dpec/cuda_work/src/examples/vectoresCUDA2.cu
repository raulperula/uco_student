/**
 * @file    vectoresCUDA2.cu
 * @brief   CUDA program.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 *
 * @use How to compile:
 *
 * nvcc vectoresCuda.cu -o vectoresCuda
 * -O (1,2,3) para optimización de código
 */

#include <iostream>
#include <time.h>
// se necesita incluir esta biblioteca para usar CUDA
#include <cuda.h>
#include <common_functions.h>

using namespace std;

void checkCUDAError(const char *msg);
void procesarConCPU(int arrayOrigen[], int arrayDestino[], int tamVector);
__global__ void d_procesarVectores(CUdeviceptr arrayOrigen, CUdeviceptr arrayDestino, int tamVector);
void procesarConGPU(int * arrayOrigen, int * arrayDestino, int tamVector);

int main(int argc, char* argv[])
{
    const int tamVector = 25000000; // Los vectores tienen 25M de elementos
    clock_t tmp;

    // se crean los dos vectores (dinamicos)
    int * arrayOrigen = new int[tamVector];
    int * arrayDestino = new int[tamVector];

    // se inicializa el primero
    for(int i=0; i<tamVector; i++) {
        arrayOrigen[i] = i;
    }

    // se mide cuánto se tarda en procesar los vectores con la CPU
    tmp = clock();
    procesarConCPU(arrayOrigen, arrayDestino, tamVector);
    clock_t tiempoConCPU = clock()-tmp;

    for(int i=0;i<10;i++){
        cout<<arrayDestino[i]<<' ';
    }
    cout<<endl;

    // se mide cuánto se tarda en procesar los vectores con la GPU
    tmp = clock();
    procesarConGPU(arrayOrigen, arrayDestino, tamVector);
    clock_t tiempoConGPU = clock()-tmp;

    for(int i=0;i<10;i++){
        cout<<arrayDestino[i]<<' ';
    }
    cout<<endl;

    //~ cout << "Los tiempos de procesamiento para "
        //~ << tamVector << " elementos son: " << endl;
    //~ cout << " * CPU: "
        //~ << ((float) tiempoConCPU)/CLOCKS_PER_SEC
        //~ << " segundos" << endl;
    //~ cout << " * GPU: "
        //~ << ((float) tiempoConGPU)/CLOCKS_PER_SEC
        //~ << " segundos" << endl;
    //~ cout << "La GPU ha sido " << ((float) tiempoConCPU)/tiempoConGPU
        //~ << " veces más rápida." << endl;
}

// procesandolo con la CPU en un bucle
// se asigna al elemento i de arrayDestino la suma de los valores de las
// posiciones i e i+1 en arrayOrigen, elevado al cubo.
void procesarConCPU(int arrayOrigen[], int arrayDestino[], int tamVector)
{
    for(int i=0; i<tamVector; i++){
        arrayDestino[i] = (arrayOrigen[i]+arrayOrigen[(i+1)%tamVector])
                        * (arrayOrigen[i]+arrayOrigen[(i+1)%tamVector])
                        * (arrayOrigen[i]+arrayOrigen[(i+1)%tamVector]);
    }
}

// procesandolo con CUDA: invocando un kernel
void procesarConGPU(int * arrayOrigen, int * arrayDestino, int tamVector)
{
    // la GPU trabaja sobre distinta RAM: se reserva memoria y se copian allí los datos.
    // poniendo el prefijo d_ nos ayuda a diferenciar los datos que están en el device (la GPU)
    CUdeviceptr d_arrayOrigen;
    CUdeviceptr d_arrayDestino;

    // cudaMalloc reserva la memoria y asigna el puntero al valor correcto
    cudaMalloc((void **) &d_arrayOrigen, sizeof(int)*tamVector);
    checkCUDAError("cudaMalloc(l.92)");
    cudaMalloc((void **) &d_arrayDestino, sizeof(int)*tamVector);
    checkCUDAError("cudaMalloc(l.94)");

    // cudaMemcpy copia los datos desde la RAM normal a la de la GPU
        // el primer argumento es la zona de memoria de destino
        // el segundo argumento es la zona de memoria de origen
        // el tercer argumento es el tamaño en bytes a copiar
        // el cuarto argumento es la dirección en la que circulan los datos
    cuMemcpyHtoD(d_arrayOrigen, arrayOrigen, sizeof(int)*tamVector);
    checkCUDAError("cudaMemcpy(l.98)");

    // esta llamada invoca al kernel, que se ejecuta en la GPU a la vez en múltiples
    // tareas organizadas en bloques
    int tamBloque = 100;
    int nBloques = tamVector/tamBloque;

    d_procesarVectores <<<tamBloque,nBloques>>> (d_arrayOrigen, d_arrayDestino, tamVector);

    // cudaMemcpy espera a que todos los kernels se hayan terminado de ejecutar
    // y copia de vuelta los datos procesados. Ahora la dirección de los datos
    // ha cambiado.
    cuMemcpyDtoH(arrayDestino, d_arrayDestino, sizeof(int)*tamVector);
    checkCUDAError("cudaMemcpy(l.111)");

    // se libera la memoria de la GPU
    //~ cudaFree(d_arrayOrigen);
    //~ checkCUDAError("cudaFree(l.)");
    //~ cudaFree(d_arrayDestino);
    //~ checkCUDAError("cudaFree(l.)");
}

// kernel que se ejecuta en paralelo en múltiples tareas para un vector
__global__ void d_procesarVectores(CUdeviceptr arrayOrigen, CUdeviceptr arrayDestino, int tamVector)
{
    // cada tarea tiene un ID numérico basado en su posición en el bloque
    int i = blockIdx.x*blockDim.x+threadIdx.x;

    // cada tarea trabaja sobre una porción de los datos
    arrayDestino[i] = (arrayOrigen[i]+arrayOrigen[(i+1)%tamVector])
                    * (arrayOrigen[i]+arrayOrigen[(i+1)%tamVector])
                    * (arrayOrigen[i]+arrayOrigen[(i+1)%tamVector]);
}

void checkCUDAError(const char *msg)
{
    cudaError_t err = cudaGetLastError();
    if(cudaSuccess != err){
        cerr<<"Cuda error: "<<msg<<": "<<cudaGetErrorString(err)<<endl;
        //~ exit(-1);
    }
}
