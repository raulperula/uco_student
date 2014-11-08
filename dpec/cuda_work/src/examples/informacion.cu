/**
 * @file    matrixMul_kernel.cu
 * @brief   CUDA program to get information of the GPU device.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license  GPL v3
 * @version 1.0.0
 */

#include <iostream>

using namespace std;

int main()
{
    cudaDeviceProp * prop;

    int count;

    cudaGetDeviceCount(&count); // se cuenta el numero de devices
    cout<<"num: "<<count<<endl;

    for(int i=0;i<count;i++){
        cudaGetDeviceProperties(prop,i); // se obtienen las propiedades del device
        cout<<"\nGeneral Information for device----"<<i<<endl;
        cout<<"Name "<<prop->name<<endl;
        cout<<"Compute capability "<<prop->major<<". "<<prop->minor<<endl;
        cout<<"Clock Rate "<<prop->clockRate<<endl;
        cout<<"Device copy overlap:  ";

        if(prop->deviceOverlap)
            cout<<"Enable\n";
        else
            cout<<"Disabled\n";

        if(prop->kernelExecTimeoutEnabled)
            cout<<"Enable\n";
        else
            cout<<"Disabled\n";

        cout<<"---Memory Information for device "<<i<<endl;
        cout<<"Total global Mem: "<<prop->totalGlobalMem<<endl;
        cout<<"Total COnstant Mem: "<<prop->totalConstMem<<endl;
        cout<<"Max mem pitch: "<<prop->memPitch<<endl;
        cout<<"Texture ALignment "<<prop->textureAlignment;
        cout<<"\n -------MP Information for devices "<<i;
        cout<<" \nMultiprocessor count : "<<prop->multiProcessorCount<<endl;
        cout<<"Shared mem per mp: "<<prop->sharedMemPerBlock<<endl;
        cout<<"Registers per mp: "<<prop->regsPerBlock<<endl;
        cout<<"Threads in warp: "<<prop->warpSize<<endl;
        cout<<"Max Threads per block "<<prop->maxThreadsPerBlock<<endl;
        cout<<"Max Threads dimensions: ("<<prop->maxThreadsDim[0]<<","<<prop->maxThreadsDim[1]
            <<","<<prop->maxThreadsDim[2]<<")\n";

        cout<<"Max grid dimensions: ("<<prop->maxGridSize[0]<<","<<prop->maxGridSize[1]
            <<","<<prop->maxGridSize[2]<<")\n";
        cout<<endl;
    }

    return 0;
}
