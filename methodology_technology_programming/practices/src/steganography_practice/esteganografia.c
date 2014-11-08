/**
 * @file    esteganografia.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include "esteganografia.h"

void obtenerLSB(int **matriz, int **matrizLSB, int fil, int col)
{
	int i, j;
	
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
			if((matriz[i][j]%2) == 0){
				matrizLSB[i][j] = 0;
			}
			else{
				matrizLSB[i][j] = 1;
			}
		}
	}
}

void obtenerMensaje(int *mensaje, int **matrizLSB, int fil, int col, int tam)
{
	int i, j, m, k = 0, l = 0;
	int v[8];
	int completado = 0;
	
	for(i=0;(i<fil)&&(!completado);i++){
		for(j=0;(j<col)&&(!completado);j++){
			v[k] = matrizLSB[i][j];
			k++;
			if(k == 8){
				for(m=0;(m<8)&&(!completado);m++){
					if(l<tam){
						mensaje[l] = v[m]*pow(2, m);
					}
					else{
						completado = 1;
					}
				}
				k = 0;
				l++;
			}
		}
	}
}

void leerMensaje(char *nombre, char *mensaje)
{
	FILE *f;
	char aux;
	int contador = 0, tam;
	
	if((f = fopen(nombre, "rt")) == NULL){
		fprintf(stderr, "\nERROR: apertura de <%s> invalida\n", nombre);
		exit(-1);
	}
	
	while((aux = fgetc()) != EOF){
		contador++;
	}
	
	if((mensaje = (char *) malloc((tam = contador+4)*sizeof(char))) == NULL){
		fprintf(stderr, "\nERROR: no ha podido asignarse memoria\n");
		exit(-1);
	}
	
	fscanf(f, "%s", mensaje);
	
	for(i=tam-4;i<tam-1;i++){
		mensaje[i] = '*';
	}
}

