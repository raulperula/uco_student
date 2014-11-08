/**
 * @file    1.4_flushOpenMP.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

/**
 Este programita suma los elementos de un vector. El número de elementos se le pasan como argumento
 y el valor de cada elemento coincide con la posición que ocupa (para hacerlo más simple)
 
*/
int main (int argc, char **argv)  {
   int nthreads, tid, hilos;
   int numElementos,i,j, indiceActual;
   int *vector, suma, aux;

   if (argc < 2){
      printf("\nSintaxis: %s numHilos\n\n",argv[0]);
      return(1);
   }

   numElementos= hilos= atoi(argv[1]);
   if (hilos < 0){
      printf("\nEl número de hilos debe ser positivo\n");
      printf("\nSintaxis: %s numHilos\n\n",argv[0]);
      return(1);
   }      
   printf("getWTime de hebra PADRE: %f \n",omp_get_wtime());

   omp_set_num_threads(hilos);		// establece el numero de hilos

   vector=malloc(numElementos*sizeof(int));

   if (vector==NULL){
      printf("\n ERROR: al reservar memoria \n");
      return(1);
   }

   for (i=0; i < numElementos; i++){
      vector[i]=1;
   }
   suma=0;   

   #pragma omp parallel shared(vector) private(tid,i,j)  // Expande un grupo de threads
      // Cada thread contiene sus propias copias de variables
   {

      tid = omp_get_thread_num(); // Obtiene el identificador del thread 
      for (i=0; i< 100000; i++){
         vector[tid]++;
         
         if (tid==0 && (vector[tid]%100)==0){
            vector[tid]++;
            #pragma omp flush(vector)
         }
                  
         if ((vector[0]%100)==0){
            if (tid!=0){
               printf("el hilo %d no ve el valor correcto de vector[0]:%d\n",tid,vector[0]++);
               #pragma omp flush(vector)
               printf("SINCRONIZADO: hilo %d, valor correcto del vector[0]:%d\n",tid,vector[0]);               
            }
         }
      }
   }
   printf("\n");
   
   printf("\ngetWTime de hebra PADRE: %f \n",omp_get_wtime());

}
