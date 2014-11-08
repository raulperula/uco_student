/**
 * @file    imagen.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
#include "imagen.h"

void cargarImagen(char *nombre, int **matriz, int *fil, int *col)
{
	FILE *f;
	int nivelGris;
	int i;
	
	if((f = fopen(nombre, "rb")) == NULL){
		fprintf(stderr, "\nERROR: apertura de <%s> invalida\n", nombre);
		exit(-1);
	}
	
	fseek(f, 2*sizeof(char), SEEK_SET);
	fscanf(f, "%d", col);
	fscanf(f, "%d", fil);
	fscanf(f, "%d", &nivelGris);
	
	if((matriz = (int **) malloc(*fil*sizeof(int *))) == NULL){
		fprintf(stderr, "\nERROR: no ha podido asignarse memoria\n");
		exit(-1);
	}
	for(i=0;i<*fil;i++){
		if((matriz[i] = (int *) malloc(*col*sizeof(int))) == NULL){
			fprintf(stderr, "\nERROR: no ha podido asignarse memoria\n");
			exit(-1);
		}
	}
	
	fread(matriz, *fil*sizeof(int), *col, f);
}

void escribirMensaje(char *nombre, int *mensaje, int tam)
{
	FILE *f;
	int i;
	
	if((f = fopen(nombre, "wt")) == NULL){
		fprintf(stderr, "\nERROR: apertura de <%s> invalida\n", nombre);
		exit(-1);
	}
	
	for(i=0;i<tam;i++){
		fprintf(f, "** MENSAJE DESCODIFICADO **\n\n");
		fprintf(f, "%c ", nombre[i]);
	}
}

