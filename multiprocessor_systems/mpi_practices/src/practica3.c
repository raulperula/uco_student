/**
 * @file    practica3.c
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
#include <mpi.h>

#define X 5
#define Y 3
#define Z 4

void getxy(int*,int*,int);

int
main(int argc, char** argv){
	int m1[X][Y];
	int m2[Y][Z];
	int m3[X][Z];
		
	int fil[X];	// Auxiliar para enviar o recibir una fila
	int col[X];	// Auxiliar para enviar o recibir una columna		
	int elem;	// Auxilear para enviar o recibir un elemento
	
	int i, j, k, l;
	int flag = 0;	// Bandera para finalizar hijos
	int nproc;
	int miproc;
	int id_envio;	// Id del proceso al que envia el master
	int elemento_actual = 0;	// Contador de elementos de la matriz
	int fil_temp, col_temp;	// Guardan filas y columnas para el envio
	int tag = 1;
	int rc;
	MPI_Status status;
	
	// Inicializar las matrices
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){
			m1[i][j] = 2;
		}
	}
	for(i=0;i<Y;i++){
		for(j=0;j<Z;j++){
			m2[i][j] = 3;
		}
	}
	
	MPI_Init(&argc, &argv);
	
	MPI_Comm_size(MPI_COMM_WORLD, &nproc);
	MPI_Comm_rank(MPI_COMM_WORLD, &miproc);
	
	if(nproc != 3){
		printf("Programa para tres procesos. Escriba -np 3\n");
		MPI_Abort(MPI_COMM_WORLD, rc);
		exit(0);
	}

	// Master
	if(miproc == 0){
		// Inicializar las matrices
		for(i=0;i<X;i++){
			for(j=0;j<Z;j++){
				elemento_actual++;
				id_envio = (j%(nproc-1))+1;
				printf("Envio a %d. Fila %d de M1. Columna %d de M2\n", id_envio, i, j);
				
				// Generar filas y columnas a enviar
				for(l=0;l<Y;l++){
					fil[l] = m1[i][l];
					col[l] = m2[l][j];
				}
				
				// Enviar fila, columna y bandera
				MPI_Send(&flag,1, MPI_INT, id_envio, tag, MPI_COMM_WORLD);
				MPI_Send(fil, Y, MPI_INT, id_envio, tag, MPI_COMM_WORLD);
				MPI_Send(col, Y, MPI_INT, id_envio, tag, MPI_COMM_WORLD);
				
				// Si ha enviado a todos los procesos, obtener los resultados parciales
				if(id_envio == (nproc-1)){
					for(k=1;k<nproc;k++){
						getxy(&fil_temp, &col_temp, elemento_actual-(nproc-1)+(k-1));
						printf("Proceso %d. Fila %d. Columna %d\n", k, fil_temp, col_temp);
						
						// Recibir resultado
						MPI_Recv(&elem, 1, MPI_INT, k, tag, MPI_COMM_WORLD, &status);
						printf("RESULTADO PARCIAL: %d\n", elem);
						
						// Colocar resultado en m3[fil_temp][col_temp]
						m3[fil_temp][col_temp] = elem;
					}
					printf("\n");
				}
			}
		}
		
		// Matriz completada
		printf("Resultados matriz:\n\n");
		for(i=0;i<X;i++){
			for(j=0;j<Z;j++){
				printf("%d\t", m3[i][j]);
			}
			printf("\n");
		}
		
		// Finalizar hijos
		flag = 1;
		for(i=1;i<nproc;i++){
			MPI_Send(&flag, 1, MPI_INT, i, tag, MPI_COMM_WORLD);
		}
		
	}
	// Hijos
	else{
		while(1){
			// Recibir bandera, fila y columna
			MPI_Recv(&flag, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
			if(flag == 1){
				break;
			}
			MPI_Recv(fil, Y, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
			MPI_Recv(col, Y, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);

			elem = 0;
			for(i=0;i<Y;i++){
				elem += fil[i]*col[i];
			}
			
			// Enviar resultado
			MPI_Send(&elem, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
		}
	}
	MPI_Finalize();
}

void getxy(int* fil_temp, int* col_temp, int elemento_actual){
	*fil_temp = elemento_actual/Z;
	*col_temp = elemento_actual%Z;
}
